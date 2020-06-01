#include <gtest/gtest.h>

#include "../include/instruction.h"

/**
 * 64 bits instruction
 **/
TEST(VM_Decode_Test, ShouldDecodeAddImm64ImstructionSuccess){
     u64 code = 0x0750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ADD_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeAddReg64ImstructionSuccess){
     u64 code = 0x0f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ADD_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeSubImm64ImstructionSuccess){
     u64 code = 0x1750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, SUB_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeSubReg64ImstructionSuccess){
     u64 code = 0x1f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, SUB_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeMulImm64ImstructionSuccess){
     u64 code = 0x2750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MUL_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeMulReg64ImstructionSuccess){
     u64 code = 0x2f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MUL_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeDivImm64ImstructionSuccess){
     u64 code = 0x3750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, DIV_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeDivReg64ImstructionSuccess){
     u64 code = 0x3f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, DIV_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeOrImm64ImstructionSuccess){
     u64 code = 0x4750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, OR_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeOrReg64ImstructionSuccess){
     u64 code = 0x4f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, OR_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeAndImm64ImstructionSuccess){
     u64 code = 0x5750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, AND_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeAndReg64ImstructionSuccess){
     u64 code = 0x5f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, AND_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeLshImm64ImstructionSuccess){
     u64 code = 0x6750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeLshReg64ImstructionSuccess){
     u64 code = 0x6f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeRshImm64ImstructionSuccess){
     u64 code = 0x7750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, RSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeRshReg64ImstructionSuccess){
     u64 code = 0x7f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, RSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeNegImm64ImstructionSuccess){
     u64 code = 0x8750000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, NEG_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
}

TEST(VM_Decode_Test, ShouldDecodeModImm64ImstructionSuccess){
     u64 code = 0x9750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOD_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeModReg64ImstructionSuccess){
     u64 code = 0x9f53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOD_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeXorImm64ImstructionSuccess){
     u64 code = 0xa750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, XOR_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeXorReg64ImstructionSuccess){
     u64 code = 0xaf53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, XOR_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeMovImm64ImstructionSuccess){
     u64 code = 0xb750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOV_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeMovReg64ImstructionSuccess){
     u64 code = 0xbf53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOV_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeArshImm64ImstructionSuccess){
     u64 code = 0xc750000000006400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ARSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeArshReg64ImstructionSuccess){
     u64 code = 0xcf53000000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ARSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

/**
 * 64 bits instruction
 **/
TEST(VM_Decode_Test, ShouldDecodeAddImm32ImstructionSuccess){
     u64 code = 0x0000000004506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ADD_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeAddReg32ImstructionSuccess){
     u64 code = 0x000000000c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ADD_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeSubImm32ImstructionSuccess){
     u64 code = 0x0000000014506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, SUB_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeSubReg32ImstructionSuccess){
     u64 code = 0x000000001c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, SUB_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeMulImm32ImstructionSuccess){
     u64 code = 0x0000000024506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MUL_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeMulReg32ImstructionSuccess){
     u64 code = 0x000000002c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MUL_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeDivImm32ImstructionSuccess){
     u64 code = 0x0000000034506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, DIV_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeDivReg32ImstructionSuccess){
     u64 code = 0x000000003c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, DIV_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeOrImm32ImstructionSuccess){
     u64 code = 0x0000000044506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, OR_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeOrReg32ImstructionSuccess){
     u64 code = 0x000000004c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, OR_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeAndImm32ImstructionSuccess){
     u64 code = 0x0000000054506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, AND_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeAndReg32ImstructionSuccess){
     u64 code = 0x000000005c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, AND_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeLshImm32ImstructionSuccess){
     u64 code = 0x0000000064506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeLshReg32ImstructionSuccess){
     u64 code = 0x000000006c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeRshImm32ImstructionSuccess){
     u64 code = 0x0000000074506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, RSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeRshReg32ImstructionSuccess){
     u64 code = 0x000000007c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, RSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeNegImm32ImstructionSuccess){
     u64 code = 0x0000000084500000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, NEG_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
}

TEST(VM_Decode_Test, ShouldDecodeModImm32ImstructionSuccess){
     u64 code = 0x0000000094506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOD_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeModReg32ImstructionSuccess){
     u64 code = 0x000000009c530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOD_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeXorImm32ImstructionSuccess){
     u64 code = 0x00000000a4506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, XOR_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeXorReg32ImstructionSuccess){
     u64 code = 0x00000000ac530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, XOR_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeMovImm32ImstructionSuccess){
     u64 code = 0x00000000b4506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOV_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeMovReg32ImstructionSuccess){
     u64 code = 0x00000000bc530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, MOV_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

TEST(VM_Decode_Test, ShouldDecodeArshImm32ImstructionSuccess){
     u64 code = 0x00000000c4506400;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ARSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
}

TEST(VM_Decode_Test, ShouldDecodeArshReg32ImstructionSuccess){
     u64 code = 0x00000000cc530000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, ARSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
}

/**
 * byteswap 
 */
TEST(VM_Decode_Test, ShouldDecodeLeReg16InstructionSuccess){
     u64 code = 0xd450000000000010;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 16);
}
TEST(VM_Decode_Test, ShouldDecodeLeReg32InstructionSuccess){
     u64 code = 0xd450000000000020;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 32);
}
TEST(VM_Decode_Test, ShouldDecodeLeReg64InstructionSuccess){
     u64 code = 0xd450000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeBeReg16InstructionSuccess){
     u64 code = 0xdc50000000000010;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 16);
}
TEST(VM_Decode_Test, ShouldDecodeBeReg32InstructionSuccess){
     u64 code = 0xdc50000000000020;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 32);
}
TEST(VM_Decode_Test, ShouldDecodeBeReg64InstructionSuccess){
     u64 code = 0xdc50000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
}

/**
 * memory instructions
 */
TEST(VM_Decode_Test, ShouldDecodeLddwInstructionSuccess){
     u64 code = 0x1850000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdabswInstructionSuccess){
     u64 code = 0x2054000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDABSW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdabshInstructionSuccess){
     u64 code = 0x2854000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDABSH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdabsbInstructionSuccess){
     u64 code = 0x3054000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDABSB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdabsdwInstructionSuccess){
     u64 code = 0x3854000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDABSDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}
TEST(VM_Decode_Test, ShouldDecodeLdindwInstructionSuccess){
     u64 code = 0x4054000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDINDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdindhInstructionSuccess){
     u64 code = 0x4854000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDINDH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdindbInstructionSuccess){
     u64 code = 0x5054000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDINDB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}


TEST(VM_Decode_Test, ShouldDecodeLdinddwInstructionSuccess){
     u64 code = 0x5854000000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDINDDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdxwInstructionSuccess){
     u64 code = 0x6154004000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDXW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdxhInstructionSuccess){
     u64 code = 0x6954004000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDXH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdxbInstructionSuccess){
     u64 code = 0x7154004000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDXB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
}

TEST(VM_Decode_Test, ShouldDecodeLdxdwInstructionSuccess){
     u64 code = 0x7954004000000000;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, LDXDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
}

TEST(VM_Decode_Test, ShouldDecodeStwInstructionSuccess){
     u64 code = 0x6250004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeSthInstructionSuccess){
     u64 code = 0x6a50004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeStbInstructionSuccess){
     u64 code = 0x7250004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeStdwInstructionSuccess){
     u64 code = 0x7a50004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Decode_Test, ShouldDecodeStxwInstructionSuccess){
     u64 code = 0x6354004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STXW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
}

TEST(VM_Decode_Test, ShouldDecodeStxhInstructionSuccess){
     u64 code = 0x6b54004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STXH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
}

TEST(VM_Decode_Test, ShouldDecodeStxbInstructionSuccess){
     u64 code = 0x7354004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STXB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
}

TEST(VM_Decode_Test, ShouldDecodeStxdwInstructionSuccess){
     u64 code = 0x7b54004000000040;
     BPFInstruction_t instruction =  vm_decode_code(code);
     ASSERT_EQ(instruction.opcode, STXDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
}

/**
 * branch instructions
 */

