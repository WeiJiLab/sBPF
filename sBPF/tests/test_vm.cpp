#include <gtest/gtest.h>

#include "../include/instruction.h"

TEST(VM_Decode_Test, ShouldDecodeAddImm64ImstructionSuccess){

     u64 code = 0x0750000000006400;
     BPFInstruction_t addImm64 =  vm_decode_code(code);

     vm_print_instruction(addImm64);

     ASSERT_EQ(addImm64.opcode, ADD_IMM_64);
     ASSERT_EQ(addImm64.destRegister, 0x05);
     ASSERT_EQ(addImm64.immediate, 0x6400);
}