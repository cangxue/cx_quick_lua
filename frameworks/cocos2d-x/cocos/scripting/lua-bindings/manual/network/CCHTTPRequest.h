#ifndef __CC_HTTP_REQUEST_H_
#define __CC_HTTP_REQUEST_H_

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

#include "cocos2d.h"
#include "curl/curl.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

using namespace std;
using namespace cocos2d;

#define kCCHTTPRequestMethodGET                 0
#define kCCHTTPRequestMethodPOST                1
#define kCCHTTPRequestMethodPUT                 2
#define kCCHTTPRequestMethodDELETE              3

#define kCCHTTPRequestAcceptEncodingIdentity    0
#define kCCHTTPRequestAcceptEncodingGzip        1
#define kCCHTTPRequestAcceptEncodingDeflate     2

#define kCCHTTPRequestStateIdle                 0
#define kCCHTTPRequestStateCleared              1
#define kCCHTTPRequestStateInProgress           2
#define kCCHTTPRequestStateCompleted            3
#define kCCHTTPRequestStateCancelled            4
#define kCCHTTPRequestStateFailed               5

#define kCCHTTPRequestCURLStateIdle             0
#define kCCHTTPRequestCURLStateBusy             1
#define kCCHTTPRequestCURLStateClosed           2

typedef vector<string> HTTPRequestHeaders;
typedef HTTPRequestHeaders::iterator HTTPRequestHeadersIterator;

class HTTPRequest : public Ref
{
public:
    static HTTPRequest* createWithUrlLua(LUA_FUNCTION listener,
                                           const char *url,
                                           int method = kCCHTTPRequestMethodGET);

    ~HTTPRequest(void);

    /** @brief Set request url. */
    void setRequestUrl(const char *url);

    /** @brief Get request url. */
    const string getRequestUrl(void);

    /** @brief Add a custom header to the request. */
    void addRequestHeader(const char *header);

    /** @brief Add a POST variable to the request, POST only. */
    void addPOSTValue(const char *key, const char *value);

    /** @brief Set POST data to the request body, POST only. */
    void setPOSTData(const char *data, size_t len = 0);

	void addFormFile(const char *name, const char *filePath, const char *fileType="application/octet-stream");
	void addFormContents(const char *name, const char *value);

    /** @brief Set/Get cookie string. */
    void setCookieString(const char *cookie);
    const string getCookieString(void);

    /** @brief Set accept encoding. */
    void setAcceptEncoding(int acceptEncoding);

    /** @brief Number of seconds to wait before timing out - default is 10. */
    void setTimeout(int timeout);

    /** @brief Execute an asynchronous request. */
    bool start(void);

    /** @brief Cancel an asynchronous request, clearing all delegates first. */
    void cancel(void);

    /** @brief Get the request state. */
    int getState(void);

    /** @brief Return HTTP status code. */
    int getResponseStatusCode(void);

    /** @brief Return HTTP response headers. */
    const HTTPRequestHeaders &getResponseHeaders(void);
    const string getResponseHeadersString(void);

    /** @brief Returns the contents of the result. */
    const string getResponseString(void);

    /** @brief Alloc memory block, return response data. use free() release memory block */
    void *getResponseData(void);

    LUA_STRING getResponseDataLua(void);

    /** @brief Get response data length (bytes). */
    int getResponseDataLength(void);

    /** @brief Save response data to file. */
    size_t saveResponseData(const char *filename);

    /** @brief Get error code. */
    int getErrorCode(void);

    /** @brief Get error message. */
    const string getErrorMessage(void);

    /** @brief timer function. */
    void checkCURLState(float dt);
    virtual void update(float dt);

private:
    HTTPRequest(void)
    : m_listener(0)
    , m_state(kCCHTTPRequestStateIdle)
    , m_errorCode(0)
    , m_responseCode(0)
    , m_responseBuffer(NULL)
    , m_responseBufferLength(0)
    , m_responseDataLength(0)
    , m_curlState(kCCHTTPRequestCURLStateIdle)
    , m_postData(NULL)
    , m_postDataLen(0)
    , m_formPost(NULL)
    , m_lastPost(NULL)
    , m_dltotal(0)
    , m_dlnow(0)
    , m_ultotal(0)
    , m_ulnow(0)
    {
    }

    bool initWithListener(LUA_FUNCTION listener, const char *url, int method);
    bool initWithUrl(const char *url, int method);

    enum {
        // how long to wait to make a successful connection to the server before starting to buffer the output
        DEFAULT_CONNECTTIMEOUT = 10, // seconds
        // how long to wait to receive a completely buffered output from the server
        DEFAULT_TIMEOUT = 30, // seconds
        BUFFER_CHUNK_SIZE = 32768, // 32 KB
    };

    static unsigned int s_id;
    string m_url;
    int m_listener;
    int m_curlState;

    CURL *m_curl;
	curl_httppost *m_formPost;
	curl_httppost *m_lastPost;

    int     m_state;
    int     m_errorCode;
    string  m_errorMessage;

    // request
    typedef map<string, string> Fields;
    Fields m_postFields;
    HTTPRequestHeaders m_headers;
    
    void* m_postData;
    size_t m_postDataLen;

    // response
    long m_responseCode;
    HTTPRequestHeaders m_responseHeaders;
    void *m_responseBuffer;
    size_t m_responseBufferLength;
    size_t m_responseDataLength;
    string m_responseCookies;
    
    double m_dltotal;
    double m_dlnow;
    double m_ultotal;
    double m_ulnow;

    // private methods
    void cleanup(void);
    void cleanupRawResponseBuff(void);

    // instance callback
    void onRequest(void);
    size_t onWriteData(void *buffer, size_t bytes);
    size_t onWriteHeader(void *buffer, size_t bytes);
    int onProgress(double dltotal, double dlnow, double ultotal, double ulnow);

    // curl callback
    static void *requestCURL(void *userdata);
    static size_t writeDataCURL(void *buffer, size_t size, size_t nmemb, void *userdata);
    static size_t writeHeaderCURL(void *buffer, size_t size, size_t nmemb, void *userdata);
    static int progressCURL(void *userdata, double dltotal, double dlnow, double ultotal, double ulnow);
};

#endif /* __CC_HTTP_REQUEST_H_ */
