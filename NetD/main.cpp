#include "include/NetManagementCoreServer.h"
#include "include/log/Log.h"

int main() {
    LogInfo("NMCS 1.0 started!")

    auto *netManagementCoreServer = new hm::netd::NetManagementCoreServer();
    netManagementCoreServer->Init();
    netManagementCoreServer->Start();

    return 0;
}
