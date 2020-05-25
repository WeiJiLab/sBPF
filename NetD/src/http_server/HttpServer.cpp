#include <unistd.h>
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

void hm::netd::HttpServer::ReceiveMessage(std::shared_ptr<hm::netd::HttpMessage> message, unsigned int fdc) {
    std::string uri = message->request.uri;
    HttpMethod method = message->request.httpMethod;
    LogInfo("[HttpServer] Request %s %s\n", message->methodToString(method).c_str(), uri.c_str())
    Route route{uri, method};
    HandlerResponse responseBody;
    if (router.count(route)) {
        std::function<HandlerResponse(HttpRequest)> &handler = this->router.find(route)->second;
        HttpRequest httpRequest = message->request;
        httpRequest.header = message->httpRequestHeader;
        responseBody = handler(httpRequest);
    } else { // 404 Not Found
        responseBody = {NOT_FOUND, HTTP_RESPONSE_404};
    }

    HttpMessage httpMessage;
    const std::string &response = httpMessage.EncodeMessage(responseBody.responseStatus, responseBody.body);

    write(fdc, response.c_str(), strlen(response.c_str()));
    close(fdc);
}

void hm::netd::HttpServer::Start() {
    if (this->worker.joinable()) {
        return;
    }
    this->socketOps->Configure(configguration.socketConfiguration);
    this->socketOps->SetUp();
    this->socketOps->Bind();
    this->socketOps->Listen();
    this->isRunning = true;
    LogInfo("[HttpServer] Http Protocol listen at port: %d\n", configguration.socketConfiguration.port)

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
    auto *httpMessage = new HttpMessage();
    std::shared_ptr<HttpMessage> message = std::make_shared<HttpMessage>();
    message = httpMessage->DecodeMessage(buffer);
    ReceiveMessage(message, fdc);
}
