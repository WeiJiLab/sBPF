cmake_minimum_required(VERSION 3.16)
project(NetD)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        src/connect/SocketOps.cpp
        src/listener/AbstractServiceListener.cpp
        src/event/NetlinkEvent.cpp
        src/netlink/NetlinkListener.cpp
        src/netlink/NetlinkHandler.cpp
        src/netlink/NetlinkManager.cpp
        src/listener/CommandListener.cpp
        src/listener/FwmarkServer.cpp
        src/listener/MDnsSdListener.cpp
        src/listener/DnsProxyListener.cpp
        src/NetManagementCoreServer.cpp
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(NetD ${SRC_LIST})
