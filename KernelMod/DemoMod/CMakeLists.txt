cmake_minimum_required(VERSION 3.16)
project(DemoMod)

set(CMAKE_CXX_STANDARD 14)

SET(Sources
        src/linux_kernel_mod_example.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_library(DemoMod ${SRC_LIST})
