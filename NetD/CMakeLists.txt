cmake_minimum_required(VERSION 3.16)
project(NetD)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        src/SocketOps.cpp
        src/AbstractServiceListener.cpp
        src/NetlinkManager.cpp
        src/CommandListener.cpp
        src/FwmarkServer.cpp
        src/MDnsSdListener.cpp
        src/DnsProxyListener.cpp
        src/NetManagementCoreServer.cpp
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(NetD ${SRC_LIST})
