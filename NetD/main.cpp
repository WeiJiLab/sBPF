#include "include/NetManagementCoreServer.h"
#include "include/log/Log.h"
#include "include/http_server/HttpServer.h"

int main() {
    LogInfo(" _____ _____ _____ _____ \n"
            "|   | |     |     |   __|\n"
            "| | | | | | |   --|__   |\n"
            "|_|___|_|_|_|_____|_____|\n"
            "                         \n"
            "       NMCS 1.0 \n")

    auto *netManagementCoreServer = new hm::netd::NetManagementCoreServer();
    netManagementCoreServer->Init();
    netManagementCoreServer->Start();

    return 0;
}
