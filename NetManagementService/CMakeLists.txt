cmake_minimum_required(VERSION 3.10)
project(NMS)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        src/DaemonConnector.cpp
        src/NetManagemnentService.cpp
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(NMS ${SRC_LIST})
