cmake_minimum_required(VERSION 3.10)
project(sBPF)

set(CMAKE_CXX_STANDARD 14)

SET(Sources src/vm.c
        main.c)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(sBPF ${SRC_LIST})
