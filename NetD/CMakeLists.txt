cmake_minimum_required(VERSION 3.10)
project(NetD)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        src/connect/SocketOps.cpp
        src/connect/SocketListener.cpp

        src/event/SocketEvent.cpp
        src/event/NetlinkEvent.cpp
        src/context/NetworkContext.cpp
        src/event/CommandNetlinkEvent.cpp
        src/netlink/NetlinkListener.cpp
        src/netlink/NetlinkHandler.cpp
        src/netlink/NetlinkManager.cpp

        src/listener/AbstractServiceListener.cpp
        src/listener/CommandListener.cpp

        src/http_server/HttpMessage.cpp
        src/http_server/HttpSocketOps.cpp
        src/http_server/HttpServer.cpp

        src/controller/NetlinkController.cpp

        src/NetManagementCoreServer.cpp
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(NetD ${SRC_LIST})


target_link_libraries(NetD pthread)
