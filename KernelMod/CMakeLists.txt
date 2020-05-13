cmake_minimum_required(VERSION 3.16)
project(KernelMod)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_library(KernelMod ${SRC_LIST})
