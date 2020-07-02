--[[
  network status and HTTP request
]]--

local network = {}

--[[
  Check if local WIFI is available.
  @function isLocalWiFiAvailable
  @return boolean
]]--
function network.isLocalWiFiAvailable()
    return cc.Network:isLocalWiFiAvailable()
end

--[[
  Check if Internet is available.
  @function isInternetConnectionAvailable
  @return boolean
]]--
function network.isInternetConnectionAvailable()
    return cc.Network:isInternetConnectionAvailable()
end

--[[
  Check if hostname is available, the method will block main thread
  @function isInternetConnectionAvailable
  @return boolean

  example:
  network.isHostNameReachable("www.baidu.com")
]]--
function network.isHostNameReachable(hostname)
    if type(hostname) ~= "string" then
        printError("network.isHostNameReachable() - invalid hostname %s", tostring(hostname))
        return false
    end
    return cc.Network:isHostNameReachable(hostname)
end

--[[
  Check Internet connect type.
  @function getInternetConnectionStatus
  @return integer
    cc.kCCNetworkStatusNotReachable
    cc.kCCNetworkStatusReachableViaWiFi
    cc.kCCNetworkStatusReachableViaWWAN
]]--
function network.getInternetConnectionStatus()
    return cc.Network:getInternetConnectionStatus()
end

--[[
  Create a http request.
  @function createHTTPRequest
  @param function callback, connection status change callback
  @param string url, the request url
  @param string method, "GET" or "POST" or "PUT" or "DELETE"
  @return cc.HTTPRequest

  example:
  local function onRequestCallback(event)
    local request = event.request
    if event.name == "completed" then
      print(request:getResponseHeadersString())
      local code = request:getResponseStatusCode()
      if code ~= 200 then
        print(code) -- get error
        return
      end
      
      -- get success
      print("response length" .. request:getResponseDataLength())
      local response = request:getResponseString()
      print(response)
    elseif event.name == "progress" then
      print("progress" .. event.dltotal)
    else
      print(event.name) -- get error
      print(request:getErrorCode(), request:getErrorMessage())
      return
    end
  end

  local request = network.createHTTPRequest(onRequestCallback, "https://baidu.com", "GET")
  request:start()
]]--
function network.createHTTPRequest(callback, url, method)
    if not method then method = "GET" end
    if string.upper(tostring(method)) == "GET" then
        method = cc.kCCHTTPRequestMethodGET
    elseif string.upper(tostring(method)) == "PUT" then
        method = cc.kCCHTTPRequestMethodPUT
    elseif string.upper(tostring(method)) == "DELETE" then
        method = cc.kCCHTTPRequestMethodDELETE
    else
        method = cc.kCCHTTPRequestMethodPOST
    end
    return cc.HTTPRequest:createWithUrl(callback, url, method)
end

--[[
  Upload a file through a HTTPRequest instance.
  @function uploadFile
  @param callback As same as the first parameter of network.createHTTPRequest.
  @param url As same as the second parameter of network.createHTTPRequest.
  @param datas Includes following values:
    fileFiledName(The input label name that type is file);
    filePath(A absolute path for a file)
    contentType(Optional, the file's contentType, default is application/octet-stream)
    extra(Optional, the key-value table that transmit to form)
  @return cc.HTTPRequest

  example:
  network.uploadFile(function(evt)
    if evt.name == "completed" then
	  local request = evt.request
	  printf("REQUEST getResponseStatusCode() = %d", request:getResponseStatusCode())
	  printf("REQUEST getResponseHeadersString() =\n%s", request:getResponseHeadersString())
	  printf("REQUEST getResponseDataLength() = %d", request:getResponseDataLength())
	  printf("REQUEST getResponseString() =\n%s", request:getResponseString())
	end
  end,
  "http://127.0.0.1/upload.php",
  {
    fileFieldName = "filepath",
	filePath = device.writablePath.."screen.jpg",
	contentType = "Image/jpeg",
	extra = {
	  {"act", "upload"},
	  {"submit", "upload"},
	}
  })
]]--
function network.uploadFile(callback, url, datas)
	assert(datas or datas.fileFieldName or datas.filePath, "Need file datas!")
	local request = network.createHTTPRequest(callback, url, "POST")
	local fileFieldName = datas.fileFieldName
	local filePath = datas.filePath
	local contentType = datas.contentType
	if contentType then
		request:addFormFile(fileFieldName, filePath, contentType)
	else
		request:addFormFile(fileFieldName, filePath)
	end
	if datas.extra then
		for i in ipairs(datas.extra) do
			local data = datas.extra[i]
			request:addFormContents(data[1], data[2])
		end
	end
	request:start()
	return request
end

local function parseTrueFalse(t)
    t = string.lower(tostring(t))
    if t == "yes" or t == "true" then return true end
    return false
end

--[[
  Convert a cookie to string.
  @function makeCookieString
  @param table cookie
  @return string
]]--
function network.makeCookieString(cookie)
    local arr = {}
    for name, value in pairs(cookie) do
        if type(value) == "table" then
            value = tostring(value.value)
        else
            value = tostring(value)
        end

        arr[#arr + 1] = tostring(name) .. "=" .. string.urlencode(value)
    end

    return table.concat(arr, "; ")
end

--[[
  Convert a string to cookie table.
  @function parseCookie
  @param string cookieString
  @return table
]]--
function network.parseCookie(cookieString)
    local cookie = {}
    local arr = string.split(cookieString, "\n")
    for _, item in ipairs(arr) do
        item = string.trim(item)
        if item ~= "" then
            local parts = string.split(item, "\t")
            -- ".amazon.com" represents the domain name of the Web server that created the cookie and will be able to read the cookie in the future
            -- TRUE indicates that all machines within the given domain can access the cookie
            -- "/" denotes the path within the domain for which the variable is valid
            -- "FALSE" indicates that the connection is not secure
            -- "2082787601" represents the expiration date in UNIX time (number of seconds since January 1, 1970 00:00:00 GMT)
            -- "ubid-main" is the name of the cookie
            -- "002-2904428-3375661" is the value of the cookie

            local c = {
                domain = parts[1],
                access = parseTrueFalse(parts[2]),
                path = parts[3],
                secure = parseTrueFalse(parts[4]),
                expire = checkint(parts[5]),
                name = parts[6],
                value = string.urldecode(parts[7]),
            }

            cookie[c.name] = c
        end
    end

    return cookie
end

return network
