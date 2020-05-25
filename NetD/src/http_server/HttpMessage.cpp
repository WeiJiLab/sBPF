//
// Created by XingfengYang on 2020/5/25.
//

#include "../../include/http_server/HttpMessage.h"
#include <assert.h>

static std::string responseReasonMap[] = {};
static std::map<std::string, hm::netd::HttpMethod> HttpMethodMap;


hm::netd::HttpMessage::~HttpMessage() noexcept = default;

hm::netd::HttpMessage::HttpMessage(hm::netd::HttpMessage &&) noexcept = default;

hm::netd::HttpMessage &hm::netd::HttpMessage::operator=(hm::netd::HttpMessage &&) noexcept = default;

hm::netd::HttpMessage::HttpMessage() {
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("GET", GET));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("HEAD", HEAD));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("POST", POST));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("PUT", PUT));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("DELETE", DELETE));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("CONNECT", CONNECT));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("OPTIONS", OPTIONS));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("TRACE", TRACE));
    HttpMethodMap.insert(std::pair<std::string, HttpMethod>("PATCH", PATCH));

    responseReasonMap[hm::netd::HttpResponseStatus::CONTINUE] = "Continue";
    responseReasonMap[hm::netd::HttpResponseStatus::SWITCHING_PROTOCOLS] = "Switching Protocols";
    responseReasonMap[hm::netd::HttpResponseStatus::PROCESSING] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::CHECKPOINT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::OK] = "OK";
    responseReasonMap[hm::netd::HttpResponseStatus::CREATED] = "Created";
    responseReasonMap[hm::netd::HttpResponseStatus::ACCEPTED] = "Accepted";
    responseReasonMap[hm::netd::HttpResponseStatus::NON_AUTHORITATIVE_INFORMATION] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NO_CONTENT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::RESET_CONTENT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PARTIAL_CONTENT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::MULTI_STATUS] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::ALREADY_REPORTED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::IM_USED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::MULTIPLE_CHOICES] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::MOVED_PERMANENTLY] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::FOUND] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::SEE_OTHER] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NOT_MODIFIED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::TEMPORARY_REDIRECT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PERMANENT_REDIRECT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::BAD_REQUEST] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::UNAUTHORIZED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PAYMENT_REQUIRED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::FORBIDDEN] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NOT_FOUND] = "Not Found";
    responseReasonMap[hm::netd::HttpResponseStatus::METHOD_NOT_ALLOWED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NOT_ACCEPTABLE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PROXY_AUTHENTICATION_REQUIRED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::REQUEST_TIMEOUT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::CONFLICT] = "Conflict";
    responseReasonMap[hm::netd::HttpResponseStatus::GONE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::LENGTH_REQUIRED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PRECONDITION_FAILED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PAYLOAD_TOO_LARGE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::URI_TOO_LONG] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::UNSUPPORTED_MEDIA_TYPE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::REQUESTED_RANGE_NOT_SATISFIABLE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::EXPECTATION_FAILED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::I_AM_A_TEAPOT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::UNPROCESSABLE_ENTITY] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::LOCKED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::FAILED_DEPENDENCY] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::UPGRADE_REQUIRED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::PRECONDITION_REQUIRED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::TOO_MANY_REQUESTS] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::REQUEST_HEADER_FIELDS_TOO_LARGE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::UNAVAILABLE_FOR_LEGAL_REASONS] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::INTERNAL_SERVER_ERROR] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NOT_IMPLEMENTED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::BAD_GATEWAY] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::SERVICE_UNAVAILABLE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::GATEWAY_TIMEOUT] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::HTTP_VERSION_NOT_SUPPORTED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::VARIANT_ALSO_NEGOTIATES] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::INSUFFICIENT_STORAGE] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::LOOP_DETECTED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::BANDWIDTH_LIMIT_EXCEEDED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NOT_EXTENDED] = "";
    responseReasonMap[hm::netd::HttpResponseStatus::NETWORK_AUTHENTICATION_REQUIRED] = "";
}

std::string hm::netd::HttpMessage::EncodeMessage(HttpResponseStatus responseStatus, const std::string &responseBody) {
    std::string response;

    // statusLine
    response.append("HTTP/1.1 ");
    response.append(std::to_string((int) responseStatus));
    response.append(" " + responseReasonMap[responseStatus] + " ");

    response.append("\r\n");
    // response header
    for (auto & it : httpRequestHeader) {
        response.append(it.first);
        response.append(":");
        response.append(it.second);
        response.append("\r\n");
    }
    response.append("\r\n");
    response.append(responseBody);
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
                    httpRequest.httpMethod = HttpMethodMap.find(buffer)->second;
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

void hm::netd::HttpMessage::SetProtocolPayload(const char *buf, char *baseLine, char *header, char *content, int processPhase) const {
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
