cmake_minimum_required(VERSION 3.10)
project(sBPF)

set(CMAKE_CXX_STANDARD 14)

SET(Sources src/vm/vm.c
        # tests/vm_decode_test.c
        # tests/vm_execute_test.c
        src/vm/hashmap.c
        # tests/hashmap_test.c
        sBPF.c)

set(SRC_LIST ${SEC_LIST} ${Sources})

add_executable(sBPF ${SRC_LIST})

target_link_libraries(sBPF gtest gtest_main pthread)

