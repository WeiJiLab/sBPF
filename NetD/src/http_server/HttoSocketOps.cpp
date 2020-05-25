#include "../../include/http_server/HttpSocketOps.h"

hm::netd::HttpSocketOps::~HttpSocketOps() noexcept = default;

hm::netd::HttpSocketOps::HttpSocketOps(hm::netd::HttpSocketOps &&) noexcept = default;

hm::netd::HttpSocketOps &hm::netd::HttpSocketOps::operator=(hm::netd::HttpSocketOps &&) noexcept = default;

hm::netd::HttpSocketOps::HttpSocketOps()
{
}

bool hm::netd::HttpSocketOps::Configure(const hm::netd::SocketConfiguration &configuration)
{
}

int hm::netd::HttpSocketOps::SetUp()
{
}

int hm::netd::HttpSocketOps::Bind()
{
}

int hm::netd::HttpSocketOps::Listen()
{
}

using SocketAcceptEventHandler = std::function<void(char *buffer, int fdc)>;
int hm::netd::HttpSocketOps::Accept(SocketAcceptEventHandler socketAcceptEventHandler)
{
}

void hm::netd::HttpSocketOps::SetSocketAcceptEventHandler(SocketAcceptEventHandler socketAcceptEventHandler)
{
}
