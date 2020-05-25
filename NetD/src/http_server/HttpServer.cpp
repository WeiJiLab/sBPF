#include "../../include/http_server/HttpServer.h"


hm::netd::HttpServer::~HttpServer() noexcept = default;

hm::netd::HttpServer::HttpServer(hm::netd::HttpServer &&) noexcept = default;

hm::netd::HttpServer &hm::netd::HttpServer::operator=(hm::netd::HttpServer &&) noexcept = default;

hm::netd::HttpServer::HttpServer() {
}

bool hm::netd::HttpServer::Configure(const hm::netd::SocketConfiguration &configuration){
}
void hm::netd::HttpServer::SetSendMessageDelegate(hm::netd::SendMessageDelegate sendMessageDelegate){
}
void hm::netd::HttpServer::ReceiveMessage(std::shared_ptr<hm::netd::HttpMessage> message,unsigned int senderInstanceNumber){
}
void hm::netd::HttpServer::Start(){
}

void hm::netd::HttpServer::AddRoute(Route route, std::function<hm::netd::HandlerResponse(hm::netd::HttpRequest)> handler){
    
}
