#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>

#include "scripting/lua-bindings/manual/network/CCHTTPRequest.h"

static bool isCurlInited = false;
unsigned int HTTPRequest::s_id = 0;

HTTPRequest *HTTPRequest::createWithUrlLua(LUA_FUNCTION listener,
                                               const char *url,
                                               int method)
{
    HTTPRequest *request = new HTTPRequest();
    request->initWithListener(listener, url, method);
    request->autorelease();
    return request;
}

bool HTTPRequest::initWithListener(LUA_FUNCTION listener, const char *url, int method)
{
    m_listener = listener;
    return initWithUrl(url, method);
}

bool HTTPRequest::initWithUrl(const char *url, int method)
{
    CCAssert(url, "HTTPRequest::initWithUrl() - invalid url");
    
    // init curl global once
    if (!isCurlInited) {
        curl_global_init(CURL_GLOBAL_ALL);
        isCurlInited = true;
    }
    
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "libcurl");
    curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT, DEFAULT_CONNECTTIMEOUT);
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, DEFAULT_TIMEOUT);
    curl_easy_setopt(m_curl, CURLOPT_NOSIGNAL, 1L);

    curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(m_curl, CURLOPT_SSL_VERIFYPEER, 0L);

    if (method == kCCHTTPRequestMethodPOST)
    {
        curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
        curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, "");
    }
	else if(method == kCCHTTPRequestMethodPUT)
	{
		curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PUT");
	}
	else if (method == kCCHTTPRequestMethodDELETE)
	{
		curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "DELETE");
	}
    
    ++s_id;
    // CCLOG("HTTPRequest[0x%04x] - create request with url: %s", s_id, url);
    return true;
}

HTTPRequest::~HTTPRequest(void)
{
    cleanup();
    if (m_listener)
    {
        LuaEngine::getInstance()->removeScriptHandler(m_listener);
    }
    // CCLOG("HTTPRequest[0x%04x] - request removed", s_id);
}

void HTTPRequest::setRequestUrl(const char *url)
{
    CCAssert(url, "HTTPRequest::setRequestUrl() - invalid url");
    m_url = url;
    curl_easy_setopt(m_curl, CURLOPT_URL, m_url.c_str());
}

const string HTTPRequest::getRequestUrl(void)
{
    return m_url;
}

void HTTPRequest::addRequestHeader(const char *header)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::addRequestHeader() - request not idle");
    CCAssert(header, "HTTPRequest::addRequestHeader() - invalid header");
    m_headers.push_back(string(header));
}

void HTTPRequest::addPOSTValue(const char *key, const char *value)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::addPOSTValue() - request not idle");
    CCAssert(key, "HTTPRequest::addPOSTValue() - invalid key");
    m_postFields[string(key)] = string(value ? value : "");
}

void HTTPRequest::setPOSTData(const char *data, size_t len)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::setPOSTData() - request not idle");
    CCAssert(data, "HTTPRequest::setPOSTData() - invalid post data");
    m_postFields.clear();
    if (0 == len) {
        len = strlen(data);
    }
    if (0 == len) {
        return;
    }
    if (m_postData)
    {
        free(m_postData);
        m_postDataLen = 0;
        m_postData = NULL;
    }
    m_postData = malloc(len + 1);
    memset(m_postData, 0, len + 1);
    if (NULL == m_postData)
    {
        return;
    }
    memcpy(m_postData, data, len);
    m_postDataLen = len;
    //curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
    //curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, data);
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, m_postData);
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDSIZE, m_postDataLen);
}

void HTTPRequest::addFormFile(const char *name, const char *filePath, const char *contentType)
{
	curl_formadd(&m_formPost, &m_lastPost,
		CURLFORM_COPYNAME, name,
		CURLFORM_FILE, filePath,
		CURLFORM_CONTENTTYPE, contentType,
		CURLFORM_END);
	//CCLOG("addFormFile %s %s %s", name, filePath, contentType);
}

void HTTPRequest::addFormContents(const char *name, const char *value)
{
	curl_formadd(&m_formPost, &m_lastPost,
		CURLFORM_COPYNAME, name,
		CURLFORM_COPYCONTENTS, value,
		CURLFORM_END);
	//CCLOG("addFormContents %s %s", name, value);
}

void HTTPRequest::setCookieString(const char *cookie)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::setAcceptEncoding() - request not idle");
    curl_easy_setopt(m_curl, CURLOPT_COOKIE, cookie ? cookie : "");
}

const string HTTPRequest::getCookieString(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::getResponseData() - request not completed");
    return m_responseCookies;
}

void HTTPRequest::setAcceptEncoding(int acceptEncoding)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::setAcceptEncoding() - request not idle");
    switch (acceptEncoding)
    {
        case kCCHTTPRequestAcceptEncodingGzip:
            curl_easy_setopt(m_curl, CURLOPT_ACCEPT_ENCODING, "gzip");
            break;
            
        case kCCHTTPRequestAcceptEncodingDeflate:
            curl_easy_setopt(m_curl, CURLOPT_ACCEPT_ENCODING, "deflate");
            break;
            
        default:
            curl_easy_setopt(m_curl, CURLOPT_ACCEPT_ENCODING, "identity");
    }
}

void HTTPRequest::setTimeout(int timeout)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::setTimeout() - request not idle");
    // CURLOPT_CONNECTTIMEOUT is ok, Only change data timeout.
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, timeout);
}

bool HTTPRequest::start(void)
{
    CCAssert(m_state == kCCHTTPRequestStateIdle, "HTTPRequest::start() - request not idle");

    m_state = kCCHTTPRequestStateInProgress;
    m_curlState = kCCHTTPRequestCURLStateBusy;
    retain();

    curl_easy_setopt(m_curl, CURLOPT_HTTP_CONTENT_DECODING, 1L);
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeDataCURL);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_curl, CURLOPT_HEADERFUNCTION, writeHeaderCURL);
    curl_easy_setopt(m_curl, CURLOPT_WRITEHEADER, this);
    curl_easy_setopt(m_curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSFUNCTION, progressCURL);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSDATA, this);
    curl_easy_setopt(m_curl, CURLOPT_COOKIEFILE, "");

    std::thread th(requestCURL, this);
    th.detach();//exit from main thread, auto exit
    
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
    // CCLOG("HTTPRequest[0x%04x] - request start", s_id);
    return true;
}

void HTTPRequest::cancel(void)
{
    if (m_state == kCCHTTPRequestStateIdle || m_state == kCCHTTPRequestStateInProgress)
    {
        m_state = kCCHTTPRequestStateCancelled;
    }
}

int HTTPRequest::getState(void)
{
    return m_state;
}

int HTTPRequest::getResponseStatusCode(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "Request not completed");
    return static_cast<int>(m_responseCode);
}

const HTTPRequestHeaders &HTTPRequest::getResponseHeaders(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::getResponseHeaders() - request not completed");
    return m_responseHeaders;
}

const string HTTPRequest::getResponseHeadersString()
{
    string buf;
    for (HTTPRequestHeadersIterator it = m_responseHeaders.begin(); it != m_responseHeaders.end(); ++it)
    {
        buf.append(*it);
    }
    return buf;
}

const string HTTPRequest::getResponseString(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::getResponseString() - request not completed");
    string rtn;
    if (m_responseBuffer) {
        rtn.assign(static_cast<char *>(m_responseBuffer), m_responseDataLength);
    }
    return rtn;
}

void *HTTPRequest::getResponseData(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::getResponseData() - request not completed");
    void *buff = malloc(m_responseDataLength);
    memcpy(buff, m_responseBuffer, m_responseDataLength);
    return buff;
}

LUA_STRING HTTPRequest::getResponseDataLua(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::getResponseDataLua() - request not completed");
    LuaStack *stack = LuaEngine::getInstance()->getLuaStack();
    stack->clean();
    stack->pushString(static_cast<char*>(m_responseBuffer), (int)m_responseDataLength);
    return 1;
}

int HTTPRequest::getResponseDataLength(void)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "Request not completed");
    return (int)m_responseDataLength;
}

size_t HTTPRequest::saveResponseData(const char *filename)
{
    CCAssert(m_state == kCCHTTPRequestStateCompleted, "HTTPRequest::saveResponseData() - request not completed");
    
    FILE *fp = fopen(filename, "wb");
    CCAssert(fp, "HTTPRequest::saveResponseData() - open file failure");
    
    size_t writedBytes = m_responseDataLength;
    if (writedBytes > 0)
    {
        fwrite(m_responseBuffer, m_responseDataLength, 1, fp);
    }
    fclose(fp);
    return writedBytes;
}

int HTTPRequest::getErrorCode(void)
{
    return m_errorCode;
}

const string HTTPRequest::getErrorMessage(void)
{
    return m_errorMessage;
}

void HTTPRequest::checkCURLState(float dt)
{
    CC_UNUSED_PARAM(dt);
    if (m_curlState != kCCHTTPRequestCURLStateBusy)
    {
        Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
        release();
    }
}

void HTTPRequest::update(float dt)
{
    if (m_state == kCCHTTPRequestStateInProgress)
    {
        if (m_listener)
        {
            LuaValueDict dict;
            
            dict["name"] = LuaValue::stringValue("progress");
            dict["total"] = LuaValue::intValue((int)m_dltotal);
            dict["dltotal"] = LuaValue::intValue((int)m_dlnow);
            dict["request"] = LuaValue::ccobjectValue(this, "HTTPRequest");
            
            LuaStack *stack = LuaEngine::getInstance()->getLuaStack();
            stack->clean();
            stack->pushLuaValueDict(dict);
            stack->executeFunctionByHandler(m_listener, 1);
        }
        return;
    }
    
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    if (m_curlState != kCCHTTPRequestCURLStateIdle)
    {
        Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(HTTPRequest::checkCURLState), this, 0, false);
    }

    if (m_listener)
    {
        LuaValueDict dict;

        switch (m_state)
        {
            case kCCHTTPRequestStateCompleted:
                dict["name"] = LuaValue::stringValue("completed");
                break;
                
            case kCCHTTPRequestStateCancelled:
                dict["name"] = LuaValue::stringValue("cancelled");
                break;
                
            case kCCHTTPRequestStateFailed:
                dict["name"] = LuaValue::stringValue("failed");
                break;
                
            default:
                dict["name"] = LuaValue::stringValue("unknown");
        }
        dict["request"] = LuaValue::ccobjectValue(this, "HTTPRequest");
        LuaStack *stack = LuaEngine::getInstance()->getLuaStack();
        stack->clean();
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(m_listener, 1);
    }
}

// instance callback

void HTTPRequest::onRequest(void)
{
    if (m_postFields.size() > 0)
    {
        //curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
        stringbuf buf;
        for (Fields::iterator it = m_postFields.begin(); it != m_postFields.end(); ++it)
        {
            char *part = curl_easy_escape(m_curl, it->first.c_str(), 0);
            buf.sputn(part, strlen(part));
            buf.sputc('=');
            curl_free(part);
            
            part = curl_easy_escape(m_curl, it->second.c_str(), 0);
            buf.sputn(part, strlen(part));
            curl_free(part);
            
            buf.sputc('&');
        }
        curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, buf.str().c_str());
    }

    struct curl_slist *chunk = NULL;
    for (HTTPRequestHeadersIterator it = m_headers.begin(); it != m_headers.end(); ++it)
    {
        chunk = curl_slist_append(chunk, (*it).c_str());
    }

	if (m_formPost)
	{
		curl_easy_setopt(m_curl, CURLOPT_HTTPPOST, m_formPost);
	}

    curl_slist *cookies = NULL;
    curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, chunk);
    CURLcode code = curl_easy_perform(m_curl);
    curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE, &m_responseCode);
    curl_easy_getinfo(m_curl, CURLINFO_COOKIELIST, &cookies);

    if (cookies)
    {
        struct curl_slist *nc = cookies;
        stringbuf buf;
        while (nc)
        {
            buf.sputn(nc->data, strlen(nc->data));
            buf.sputc('\n');
            nc = nc->next;
        }
        m_responseCookies = buf.str();
        curl_slist_free_all(cookies);
        cookies = NULL;
    }

    curl_easy_cleanup(m_curl);
    m_curl = NULL;
	if (m_formPost)
	{
		curl_formfree(m_formPost);
		m_formPost = NULL;
	}
    curl_slist_free_all(chunk);
    
    m_errorCode = code;
    m_errorMessage = (code == CURLE_OK) ? "" : curl_easy_strerror(code);
    m_state = (code == CURLE_OK) ? kCCHTTPRequestStateCompleted : kCCHTTPRequestStateFailed;
    m_curlState = kCCHTTPRequestCURLStateClosed;
}

size_t HTTPRequest::onWriteData(void *buffer, size_t bytes)
{
    if (m_responseDataLength + bytes + 1 > m_responseBufferLength)
    {
        m_responseBufferLength += BUFFER_CHUNK_SIZE;
        m_responseBuffer = realloc(m_responseBuffer, m_responseBufferLength);
    }

    memcpy(static_cast<char*>(m_responseBuffer) + m_responseDataLength, buffer, bytes);
    m_responseDataLength += bytes;
    static_cast<char*>(m_responseBuffer)[m_responseDataLength] = 0;
    return bytes;
}

size_t HTTPRequest::onWriteHeader(void *buffer, size_t bytes)
{
    char *headerBuffer = new char[bytes + 1];
    headerBuffer[bytes] = 0;
    memcpy(headerBuffer, buffer, bytes);    
    m_responseHeaders.push_back(string(headerBuffer));
    delete []headerBuffer;
    return bytes;
}

int HTTPRequest::onProgress(double dltotal, double dlnow, double ultotal, double ulnow)
{
    m_dltotal = dltotal;
    m_dlnow = dlnow;
    m_ultotal = ultotal;
    m_ulnow = ulnow;
    
    return m_state == kCCHTTPRequestStateCancelled ? 1: 0;
}

void HTTPRequest::cleanup(void)
{
    m_state = kCCHTTPRequestStateCleared;
    m_responseBufferLength = 0;
    m_responseDataLength = 0;
    m_postDataLen = 0;
    if (m_postData)
    {
        free(m_postData);
        m_postData = NULL;
    }
    if (m_responseBuffer)
    {
        free(m_responseBuffer);
        m_responseBuffer = NULL;
    }
    if (m_curl)
    {
        curl_easy_cleanup(m_curl);
        m_curl = NULL;
    }
}

// curl callback
void *HTTPRequest::requestCURL(void *userdata)
{
    static_cast<HTTPRequest*>(userdata)->onRequest();
    return NULL;
}

size_t HTTPRequest::writeDataCURL(void *buffer, size_t size, size_t nmemb, void *userdata)
{
    return static_cast<HTTPRequest*>(userdata)->onWriteData(buffer, size *nmemb);
}

size_t HTTPRequest::writeHeaderCURL(void *buffer, size_t size, size_t nmemb, void *userdata)
{
    return static_cast<HTTPRequest*>(userdata)->onWriteHeader(buffer, size *nmemb);
}

int HTTPRequest::progressCURL(void *userdata, double dltotal, double dlnow, double ultotal, double ulnow)
{
    return static_cast<HTTPRequest*>(userdata)->onProgress(dltotal, dlnow, ultotal, ulnow);
}
