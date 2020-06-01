#include <unistd.h>
#include <cstring>
#include "../../include/http_server/HttpServer.h"
#include "../../include/log/Log.h"


hm::netd::HttpServer::~HttpServer() noexcept = default;

hm::netd::HttpServer::HttpServer(hm::netd::HttpServer &&) noexcept = default;

hm::netd::HttpServer &hm::netd::HttpServer::operator=(hm::netd::HttpServer &&) noexcept = default;

hm::netd::HttpServer::HttpServer() : socketOps(std::make_shared<HttpSocketOps>()) {
}

bool hm::netd::HttpServer::Configure(const hm::netd::HttpServerConfigguration &configuration) {
    this->configguration = configuration;
}

#define HTTP_RESPONSE_404 "<h1>404 Not Found:</h1><p>What you are looking for is missed.</p>"

void hm::netd::HttpServer::ReceiveMessage(hm::netd::HttpRequest request, unsigned int fdc) {
    std::string uri = request.uri;
    HttpMethod method = request.httpMethod;
    HttpMessage httpMessage;
    LogInfo("[HttpServer] Request %s %s", httpMessage.MethodToString(method).c_str(), uri.c_str())
    Route route{uri, method};
    HandlerResponse responseBody;

    if (router.count(route)) {
        LogInfo("[HttpServer] Route found for %s", uri.c_str())
        std::function<HandlerResponse(HttpRequest)> &handler = this->router.find(route)->second;
        HttpRequest httpRequest = request;
        httpRequest.header = request.header;
        responseBody = handler(httpRequest);
    } else { // 404 Not Found
        LogWarnning("[HttpServer] Route not found for %s", uri.c_str())
        responseBody = {NOT_FOUND, HTTP_RESPONSE_404};
    }

    const std::string &response = httpMessage.EncodeMessage(responseBody.responseStatus, responseBody.body, request.header);

    write(fdc, response.c_str(), strlen(response.c_str()));
    if (!request.header.count("keep-Alive")) {
        close(fdc);
    }

}

void hm::netd::HttpServer::Start() {
    if (this->worker.joinable()) {
        LogError("[HttpServer] Worker not joinable: %d", configguration.socketConfiguration.port)
        return;
    }
    this->socketOps->Configure(configguration.socketConfiguration);
    this->socketOps->SetUp();
    this->socketOps->Bind();
    this->socketOps->Listen();
    this->isRunning = true;
    LogInfo("[HttpServer] Http Protocol listen at port: %d", configguration.socketConfiguration.port)

    this->worker = std::thread(&HttpServer::ServerWorker, this);
}

void hm::netd::HttpServer::AddRoute(Route route, std::function<hm::netd::HandlerResponse(hm::netd::HttpRequest)> handler) {
    this->router.insert(std::pair<Route, std::function<HandlerResponse(HttpRequest)>>(route, handler));
}

void hm::netd::HttpServer::ServerWorker() {
    while (isRunning) {
        const auto bind = std::bind(&HttpServer::Handler, this, std::placeholders::_1, std::placeholders::_2);
        this->socketOps->Accept(bind);
    }
}

void hm::netd::HttpServer::Handler(char *buffer, int fdc) {
    HttpMessage httpMessage;
    HttpRequest httpRequest = httpMessage.DecodeMessage(buffer);
    ReceiveMessage(httpRequest, fdc);
}

bool hm::netd::Route::operator==(const hm::netd::Route &rhs) const {
    return uri == rhs.uri &&
           method == rhs.method;
}

bool hm::netd::Route::operator!=(const hm::netd::Route &rhs) const {
    return !(rhs == *this);
}

bool hm::netd::Route::operator<(const hm::netd::Route &rhs) const {
    if (uri < rhs.uri)
        return true;
    if (rhs.uri < uri)
        return false;
    return method < rhs.method;
}

bool hm::netd::Route::operator>(const hm::netd::Route &rhs) const {
    return rhs < *this;
}

bool hm::netd::Route::operator<=(const hm::netd::Route &rhs) const {
    return !(rhs < *this);
}

bool hm::netd::Route::operator>=(const hm::netd::Route &rhs) const {
    return !(*this < rhs);
}
