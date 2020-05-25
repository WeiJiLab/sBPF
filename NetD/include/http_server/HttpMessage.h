#ifndef _NMCS_HTTP_MESSAGE_H_
#define _NMCS_HTTP_MESSAGE_H_
#include <memory>
#include <map>
#include <string>

namespace hm
{
    namespace netd
    {
         enum HttpResponseStatus {
            CONTINUE = 100,
            SWITCHING_PROTOCOLS = 101,
            PROCESSING = 102,
            CHECKPOINT = 103,
            OK = 200,
            CREATED = 201,
            ACCEPTED = 202,
            NON_AUTHORITATIVE_INFORMATION = 203,
            NO_CONTENT = 204,
            RESET_CONTENT = 205,
            PARTIAL_CONTENT = 206,
            MULTI_STATUS = 207,
            ALREADY_REPORTED = 208,
            IM_USED = 226,
            MULTIPLE_CHOICES = 300,
            MOVED_PERMANENTLY = 301,
            FOUND = 302,
            SEE_OTHER = 303,
            NOT_MODIFIED = 304,
            TEMPORARY_REDIRECT = 307,
            PERMANENT_REDIRECT = 308,
            BAD_REQUEST = 400,
            UNAUTHORIZED = 401,
            PAYMENT_REQUIRED = 402,
            FORBIDDEN = 403,
            NOT_FOUND = 404,
            METHOD_NOT_ALLOWED = 405,
            NOT_ACCEPTABLE = 406,
            PROXY_AUTHENTICATION_REQUIRED = 407,
            REQUEST_TIMEOUT = 408,
            CONFLICT = 409,
            GONE = 410,
            LENGTH_REQUIRED = 411,
            PRECONDITION_FAILED = 412,
            PAYLOAD_TOO_LARGE = 413,
            URI_TOO_LONG = 414,
            UNSUPPORTED_MEDIA_TYPE = 415,
            REQUESTED_RANGE_NOT_SATISFIABLE = 416,
            EXPECTATION_FAILED = 417,
            I_AM_A_TEAPOT = 418,
            UNPROCESSABLE_ENTITY = 422,
            LOCKED = 423,
            FAILED_DEPENDENCY = 424,
            UPGRADE_REQUIRED = 426,
            PRECONDITION_REQUIRED = 428,
            TOO_MANY_REQUESTS = 429,
            REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
            UNAVAILABLE_FOR_LEGAL_REASONS = 451,
            INTERNAL_SERVER_ERROR = 500,
            NOT_IMPLEMENTED = 501,
            BAD_GATEWAY = 502,
            SERVICE_UNAVAILABLE = 503,
            GATEWAY_TIMEOUT = 504,
            HTTP_VERSION_NOT_SUPPORTED = 505,
            VARIANT_ALSO_NEGOTIATES = 506,
            INSUFFICIENT_STORAGE = 507,
            LOOP_DETECTED = 508,
            BANDWIDTH_LIMIT_EXCEEDED = 509,
            NOT_EXTENDED = 510,
            NETWORK_AUTHENTICATION_REQUIRED = 511,
        };

        enum HttpMethod {
            GET,
            HEAD,
            POST,
            PUT,
            DELETE,
            CONNECT,
            OPTIONS,
            TRACE,
            PATCH,
        };

        struct HttpRequest {
            std::string uri;
            HttpMethod httpMethod;
            std::string protocol;
            std::map<std::string, std::string> header;
            std::map<std::string, std::string> params;
            std::string body;
        };

        struct Header {
            std::string name;
            std::string value;
        };
    class HttpMessage {
    public:
        ~HttpMessage() noexcept;

        HttpMessage(const HttpMessage &) = delete;

        HttpMessage(HttpMessage &&) noexcept;

        HttpMessage &operator=(const HttpMessage &) = delete;

        HttpMessage &operator=(HttpMessage &&) noexcept;

    public:
        std::string EncodeMessage(HttpResponseStatus responseStatus, const std::string &responseBody);

        std::shared_ptr<HttpMessage> DecodeMessage(char *buf);

    public:
        HttpMessage();

        std::string methodToString(HttpMethod method);

    private:
        void SetProtocolPayload(const char *buf, char *baseLine, char *header, char *content, int processPhase) const;

    public:
        std::map<std::string, std::string> httpRequestHeader;

        std::map<std::string, HttpMethod> httpMethodMap;

        HttpRequest request;
    };
    } // namespace netd 
} // namespace hm
#endif