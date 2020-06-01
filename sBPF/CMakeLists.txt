cmake_minimum_required(VERSION 3.10)
project(sBPF)

set(CMAKE_CXX_STANDARD 14)

SET(Sources src/vm.cpp
        tests/test_vm.cpp
        main.cpp)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(sBPF ${SRC_LIST})

target_link_libraries(sBPF pthread gtest gtest_main)
