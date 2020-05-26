//
// Created by XingfengYang on 2020/5/25.
//

#include "../../include/http_server/HttpMessage.h"
#include "../../include/log/Log.h"
#include <assert.h>

hm::netd::HttpMessage::~HttpMessage() noexcept = default;

hm::netd::HttpMessage::HttpMessage(hm::netd::HttpMessage &&) noexcept = default;

hm::netd::HttpMessage &hm::netd::HttpMessage::operator=(hm::netd::HttpMessage &&) noexcept = default;

hm::netd::HttpMessage::HttpMessage() {
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("GET", GET));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("HEAD", HEAD));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("POST", POST));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("PUT", PUT));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("DELETE", DELETE));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("CONNECT", CONNECT));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("OPTIONS", OPTIONS));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("TRACE", TRACE));
    httpMethodMap.insert(std::pair<std::string, HttpMethod>("PATCH", PATCH));

    responseReasonMap[CONTINUE] = "Continue";
    responseReasonMap[SWITCHING_PROTOCOLS] = "Switching Protocols";
    responseReasonMap[PROCESSING] = "";
    responseReasonMap[CHECKPOINT] = "";
    responseReasonMap[OK] = "OK";
    responseReasonMap[CREATED] = "Created";
    responseReasonMap[ACCEPTED] = "Accepted";
    responseReasonMap[NON_AUTHORITATIVE_INFORMATION] = "";
    responseReasonMap[NO_CONTENT] = "";
    responseReasonMap[RESET_CONTENT] = "";
    responseReasonMap[PARTIAL_CONTENT] = "";
    responseReasonMap[MULTI_STATUS] = "";
    responseReasonMap[ALREADY_REPORTED] = "";
    responseReasonMap[IM_USED] = "";
    responseReasonMap[MULTIPLE_CHOICES] = "";
    responseReasonMap[MOVED_PERMANENTLY] = "";
    responseReasonMap[FOUND] = "";
    responseReasonMap[SEE_OTHER] = "";
    responseReasonMap[NOT_MODIFIED] = "";
    responseReasonMap[TEMPORARY_REDIRECT] = "";
    responseReasonMap[PERMANENT_REDIRECT] = "";
    responseReasonMap[BAD_REQUEST] = "";
    responseReasonMap[UNAUTHORIZED] = "";
    responseReasonMap[PAYMENT_REQUIRED] = "";
    responseReasonMap[FORBIDDEN] = "";
    responseReasonMap[NOT_FOUND] = "Not Found";
    responseReasonMap[METHOD_NOT_ALLOWED] = "";
    responseReasonMap[NOT_ACCEPTABLE] = "";
    responseReasonMap[PROXY_AUTHENTICATION_REQUIRED] = "";
    responseReasonMap[REQUEST_TIMEOUT] = "";
    responseReasonMap[CONFLICT] = "Conflict";
    responseReasonMap[GONE] = "";
    responseReasonMap[LENGTH_REQUIRED] = "";
    responseReasonMap[PRECONDITION_FAILED] = "";
    responseReasonMap[PAYLOAD_TOO_LARGE] = "";
    responseReasonMap[URI_TOO_LONG] = "";
    responseReasonMap[UNSUPPORTED_MEDIA_TYPE] = "";
    responseReasonMap[REQUESTED_RANGE_NOT_SATISFIABLE] = "";
    responseReasonMap[EXPECTATION_FAILED] = "";
    responseReasonMap[I_AM_A_TEAPOT] = "";
    responseReasonMap[UNPROCESSABLE_ENTITY] = "";
    responseReasonMap[LOCKED] = "";
    responseReasonMap[FAILED_DEPENDENCY] = "";
    responseReasonMap[UPGRADE_REQUIRED] = "";
    responseReasonMap[PRECONDITION_REQUIRED] = "";
    responseReasonMap[TOO_MANY_REQUESTS] = "";
    responseReasonMap[REQUEST_HEADER_FIELDS_TOO_LARGE] = "";
    responseReasonMap[UNAVAILABLE_FOR_LEGAL_REASONS] = "";
    responseReasonMap[INTERNAL_SERVER_ERROR] = "";
    responseReasonMap[NOT_IMPLEMENTED] = "";
    responseReasonMap[BAD_GATEWAY] = "";
    responseReasonMap[SERVICE_UNAVAILABLE] = "";
    responseReasonMap[GATEWAY_TIMEOUT] = "";
    responseReasonMap[HTTP_VERSION_NOT_SUPPORTED] = "";
    responseReasonMap[VARIANT_ALSO_NEGOTIATES] = "";
    responseReasonMap[INSUFFICIENT_STORAGE] = "";
    responseReasonMap[LOOP_DETECTED] = "";
    responseReasonMap[BANDWIDTH_LIMIT_EXCEEDED] = "";
    responseReasonMap[NOT_EXTENDED] = "";
    responseReasonMap[NETWORK_AUTHENTICATION_REQUIRED] = "";
}

std::string hm::netd::HttpMessage::EncodeMessage(HttpResponseStatus responseStatus, const std::string &responseBody,std::map<std::string,std::string> headers) {
    std::string response;
    LogInfo("[HttpServer] Encode Http Request")
    // statusLine
    response.append("HTTP/1.1 ");
    response.append(std::to_string((int) responseStatus));
    response.append(" " + responseReasonMap[responseStatus] + " ");

    response.append("\r\n");
    // response header
    for (auto & it : headers) {
        response.append(it.first);
        response.append(":");
        response.append(it.second);
        response.append("\r\n");
    }
    response.append("\r\n");
    response.append(responseBody);
    LogInfo("[HttpServer] Http Request Encoded")
    return response;
}

/**
   * GET /resource HTTP/1.1\n\n
   * header1: value1\r\n
   * header2: value2\r\n
   * ...
   * headern: valuen\r\n
   * \r\n
   * content
   */
hm::netd::HttpRequest hm::netd::HttpMessage::DecodeMessage(char *buf) {

    std::string request(buf);
    std::map<std::string, std::string> httpRequestHeader;

    HttpRequest httpRequest;

    /**
     * PROCESS_METHOD->PROCESS_RESOURCE->PROCESS_PROTOCOL->PROCESS_HEADER_NAME->PROCESS_HEADER_VALUE->PROCESS_CONTENT
     *                                                    |                                          |
     *                                                     <-----------------------------------------
     */
    enum ProcessState {
        PROCESS_METHOD,
        PROCESS_RESOURCE,
        PROCESS_PROTOCOL,
        PROCESS_HEADER_NAME,
        PROCESS_HEADER_VALUE,
        PROCESS_CONTENT
    };

    ProcessState processState = ProcessState::PROCESS_METHOD;

    int index = 0;
    std::string buffer;
    size_t length = request.size();
    auto consume = [&]() -> char {
        assert(index < length);
        return buf[index++];
    };

    auto peek = [&](uint32_t offset) -> char {
        assert(index + offset < length);
        return buf[index + offset];
    };

    auto transformState = [&](ProcessState nextState) {
        buffer.clear();
        processState = nextState;
    };

    std::string currentHeaderName;
    while (index < length) {
        char currentChr = consume();
        switch (processState) {
            case PROCESS_METHOD:
                if (currentChr == ' ') {
                    httpRequest.httpMethod = httpMethodMap.find(buffer)->second;
                    transformState(PROCESS_RESOURCE);
                } else {
                    buffer.push_back(currentChr);
                }
                break;
            case PROCESS_RESOURCE:
                if (currentChr == ' ') {
                    httpRequest.uri = buffer;
                    transformState(PROCESS_PROTOCOL);
                } else {
                    buffer.push_back(currentChr);
                }
                break;
            case PROCESS_PROTOCOL:
                if (currentChr == '\r' && consume() == '\n') {
                    httpRequest.protocol = buffer;
                    transformState(PROCESS_HEADER_NAME);
                } else {
                    buffer.push_back(currentChr);
                }
                break;
            case PROCESS_HEADER_NAME:
                if (currentChr == ':' && consume() == ' ') {
                    currentHeaderName = buffer;
                    transformState(PROCESS_HEADER_VALUE);
                } else {
                    buffer.push_back(currentChr);
                }
                break;
            case PROCESS_HEADER_VALUE:
                if (currentChr == '\r' && consume() == '\n') {
                    httpRequest.header.insert(std::pair<std::string, std::string>(currentHeaderName, buffer));
                    buffer.clear();
                    if (peek(0) == '\r' && peek(1) == '\n') {
                        consume();
                        consume();
                        processState = PROCESS_CONTENT;
                    } else {
                        processState = PROCESS_HEADER_NAME;
                    }
                } else {
                    buffer.push_back(currentChr);
                }
                break;
            case PROCESS_CONTENT:
                buffer.push_back(currentChr);
                if (index == length) {
                    httpRequest.body = buffer;
                }
                break;
        }
    }

    return httpRequest;
}

std::string hm::netd::HttpMessage::MethodToString(HttpMethod method) {
    switch (method) {
        case GET:
            return "GET";
        case HEAD:
            return "HEAD";
        case POST:
            return "POST";
        case PUT:
            return "PUT";
        case DELETE:
            return "DELETE";
        case CONNECT:
            return "CONNECT";
        case OPTIONS:
            return "OPTIONS";
        case TRACE:
            return "TRACE";
        case PATCH:
            return "PATCH";
    }
}
