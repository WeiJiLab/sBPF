#include <gtest/gtest.h>

#include "../include/vm/instruction.h"

/**
 * 64 bits instruction
 **/
TEST(VM_Execute_Test, ShouldExecuteAddImm64InstructionSuccess){
     u64 code = 0x0750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ADD_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400+10);
}

TEST(VM_Execute_Test, ShouldExecuteAddReg64InstructionSuccess){
     u64 code = 0x0f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ADD_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10+10);
}

TEST(VM_Execute_Test, ShouldExecuteSubImm64InstructionSuccess){
     u64 code = 0x1750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, SUB_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10-0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteSubReg64InstructionSuccess){
     u64 code = 0x1f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, SUB_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20-10);
}

TEST(VM_Execute_Test, ShouldExecuteMulImm64InstructionSuccess){
     u64 code = 0x2750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MUL_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400*10);
}

TEST(VM_Execute_Test, ShouldExecuteMulReg64InstructionSuccess){
     u64 code = 0x2f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MUL_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20*10);
}

TEST(VM_Execute_Test, ShouldExecuteDivImm64InstructionSuccess){
     u64 code = 0x3750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, DIV_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10/0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteDivReg64InstructionSuccess){
     u64 code = 0x3f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, DIV_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20/10);
}

TEST(VM_Execute_Test, ShouldExecuteOrImm64InstructionSuccess){
     u64 code = 0x4750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, OR_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 | 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteOrReg64InstructionSuccess){
     u64 code = 0x4f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, OR_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 | 10);
}

TEST(VM_Execute_Test, ShouldExecuteAndImm64InstructionSuccess){
     u64 code = 0x5750000000006400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, AND_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 & 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteAndReg64InstructionSuccess){
     u64 code = 0x5f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, AND_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 & 10);
}

TEST(VM_Execute_Test, ShouldExecuteLshImm64InstructionSuccess){
     u64 code = 0x6750000000000004;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 << 0x04);
}

TEST(VM_Execute_Test, ShouldExecuteLshReg64InstructionSuccess){
     u64 code = 0x6f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 << 10);
}

TEST(VM_Execute_Test, ShouldExecuteRshImm64InstructionSuccess){
     u64 code = 0x7750000000000004;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, RSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 >> 0x04);
}

TEST(VM_Execute_Test, ShouldExecuteRshReg64InstructionSuccess){
     u64 code = 0x7f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, RSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 >> 10);
}

TEST(VM_Execute_Test, ShouldExecuteNegImm64InstructionSuccess){
     u64 code = 0x8750000000000000;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, NEG_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], -10);
}

TEST(VM_Execute_Test, ShouldExecuteModImm64InstructionSuccess){
     u64 code = 0x9750000000006400;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOD_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 % 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteModReg64InstructionSuccess){
     u64 code = 0x9f53000000000000;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOD_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 % 10);
}

TEST(VM_Execute_Test, ShouldExecuteXorImm64InstructionSuccess){
     u64 code = 0xa750000000006400;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, XOR_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 ^ 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteXorReg64InstructionSuccess){
     u64 code = 0xaf53000000000000;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, XOR_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 ^ 10);
}

TEST(VM_Execute_Test, ShouldExecuteMovImm64InstructionSuccess){
     u64 code = 0xb750000000006400;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOV_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteMovReg64InstructionSuccess){
     u64 code = 0xbf53000000000000;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOV_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10);
}

TEST(VM_Execute_Test, ShouldExecuteArshImm64InstructionSuccess){
     u64 code = 0xc750000000000004;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ARSH_IMM_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = (u64)(-64);
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], (-64)>>0x04);
}

TEST(VM_Execute_Test, ShouldExecuteArshReg64InstructionSuccess){
     u64 code = 0xcf53000000000000;
     VM_t vm;
     BPFInstruction_t instruction = vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ARSH_REG_64);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = (u64)(-64);
     vm.regs[0x3] = 2;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], (-64)>>2);
}

/**
 * 32 bits instruction
 **/
TEST(VM_Execute_Test, ShouldExecuteAddImm32InstructionSuccess){
     u64 code = 0x0000000004506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ADD_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400+10);
}

TEST(VM_Execute_Test, ShouldExecuteAddReg32InstructionSuccess){
     u64 code = 0x000000000c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ADD_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10+10);
}

TEST(VM_Execute_Test, ShouldExecuteSubImm32InstructionSuccess){
     u64 code = 0x0000000014506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, SUB_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10-0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteSubReg32InstructionSuccess){
     u64 code = 0x000000001c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, SUB_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20-10);
}

TEST(VM_Execute_Test, ShouldExecuteMulImm32InstructionSuccess){
     u64 code = 0x0000000024506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MUL_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400*10);
}

TEST(VM_Execute_Test, ShouldExecuteMulReg32InstructionSuccess){
     u64 code = 0x000000002c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MUL_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20*10);
}

TEST(VM_Execute_Test, ShouldExecuteDivImm32InstructionSuccess){
     u64 code = 0x0000000034506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, DIV_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10/0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteDivReg32InstructionSuccess){
     u64 code = 0x000000003c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, DIV_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20/10);
}

TEST(VM_Execute_Test, ShouldExecuteOrImm32InstructionSuccess){
     u64 code = 0x0000000044506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, OR_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400|10);
}

TEST(VM_Execute_Test, ShouldExecuteOrReg32InstructionSuccess){
     u64 code = 0x000000004c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, OR_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20|10);
}

TEST(VM_Execute_Test, ShouldExecuteAndImm32InstructionSuccess){
     u64 code = 0x0000000054506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, AND_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400 & 10);
}

TEST(VM_Execute_Test, ShouldExecuteAndReg32InstructionSuccess){
     u64 code = 0x000000005c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, AND_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 & 10);
}

TEST(VM_Execute_Test, ShouldExecuteLshImm32InstructionSuccess){
     u64 code = 0x0000000064500004;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 << 0x04);
}

TEST(VM_Execute_Test, ShouldExecuteLshReg32InstructionSuccess){
     u64 code = 0x000000006c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 << 10);
}

TEST(VM_Execute_Test, ShouldExecuteRshImm32InstructionSuccess){
     u64 code = 0x0000000074500004;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, RSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 >> 0x04);
}

TEST(VM_Execute_Test, ShouldExecuteRshReg32InstructionSuccess){
     u64 code = 0x000000007c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, RSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 >> 10);
}

TEST(VM_Execute_Test, ShouldExecuteNegImm32InstructionSuccess){
     u64 code = 0x0000000084500000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, NEG_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], -20);
}

TEST(VM_Execute_Test, ShouldExecuteModImm32InstructionSuccess){
     u64 code = 0x0000000094506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOD_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 % 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteModReg32InstructionSuccess){
     u64 code = 0x000000009c530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOD_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 % 10);
}

TEST(VM_Execute_Test, ShouldExecuteXorImm32InstructionSuccess){
     u64 code = 0x00000000a4506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, XOR_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10 ^ 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteXorReg32InstructionSuccess){
     u64 code = 0x00000000ac530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, XOR_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 20 ^ 10);
}

TEST(VM_Execute_Test, ShouldExecuteMovImm32InstructionSuccess){
     u64 code = 0x00000000b4506400;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOV_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x6400);
     vm_init(vm,0);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 0x6400);
}

TEST(VM_Execute_Test, ShouldExecuteMovReg32InstructionSuccess){
     u64 code = 0x00000000bc530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, MOV_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = 20;
     vm.regs[0x3] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], 10);
}

TEST(VM_Execute_Test, ShouldExecuteArshImm32InstructionSuccess){
     u64 code = 0x00000000c4500004;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ARSH_IMM_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 0x04);
     vm_init(vm,0);
     vm.regs[0x5] = -64;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], (-64)>>0x04);
}

TEST(VM_Execute_Test, ShouldExecuteArshReg32InstructionSuccess){
     u64 code = 0x00000000cc530000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, ARSH_REG_32);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x03);
     vm_init(vm,0);
     vm.regs[0x5] = -64;
     vm.regs[0x3] = 2;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05], (-64)>>2);
}

/**
 * byteswap
 */
TEST(VM_Execute_Test, ShouldExecuteLeReg16InstructionSuccess){
     u64 code = 0xd450000000000010;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 16);
}

TEST(VM_Execute_Test, ShouldExecuteLeReg32InstructionSuccess){
     u64 code = 0xd450000000000020;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 32);
}

TEST(VM_Execute_Test, ShouldExecuteLeReg64InstructionSuccess){
     u64 code = 0xd450000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteBeReg16InstructionSuccess){
     u64 code = 0xdc50000000000010;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 16);
}

TEST(VM_Execute_Test, ShouldExecuteBeReg32InstructionSuccess){
     u64 code = 0xdc50000000000020;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 32);
}

TEST(VM_Execute_Test, ShouldExecuteBeReg64InstructionSuccess){
     u64 code = 0xdc50000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, BE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
}

/**
 * memory instructions
 */
TEST(VM_Execute_Test, ShouldExecuteLddwInstructionSuccess){
     u64 code = 0x1850000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05],64);
}

TEST(VM_Execute_Test, ShouldExecuteLdabswInstructionSuccess){
     u64 code = 0x2054000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDABSW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdabshInstructionSuccess){
     u64 code = 0x2854000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDABSH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdabsbInstructionSuccess){
     u64 code = 0x3054000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDABSB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdabsdwInstructionSuccess){
     u64 code = 0x3854000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDABSDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdindwInstructionSuccess){
     u64 code = 0x4054000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDINDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdindhInstructionSuccess){
     u64 code = 0x4854000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDINDH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdindbInstructionSuccess){
     u64 code = 0x5054000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDINDB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdinddwInstructionSuccess){
     u64 code = 0x5854000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDINDDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteLdxwInstructionSuccess){
     u64 code = 0x6154004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDXW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.memory[74] = 30;
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05],30);
}

TEST(VM_Execute_Test, ShouldExecuteLdxhInstructionSuccess){
     u64 code = 0x6954004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDXH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.memory[74] = 30;
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05],30);
}

TEST(VM_Execute_Test, ShouldExecuteLdxbInstructionSuccess){
     u64 code = 0x7154004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDXB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.memory[74] = 30;
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05],30);
}

TEST(VM_Execute_Test, ShouldExecuteLdxdwInstructionSuccess){
     u64 code = 0x7954004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, LDXDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x4);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.memory[74] = 30;
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.regs[0x05],30);
}

TEST(VM_Execute_Test, ShouldExecuteStwInstructionSuccess){
     u64 code = 0x6250004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],64);
}

TEST(VM_Execute_Test, ShouldExecuteSthInstructionSuccess){
     u64 code = 0x6a50004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],64);
}

TEST(VM_Execute_Test, ShouldExecuteStbInstructionSuccess){
     u64 code = 0x7250004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],64);
}

TEST(VM_Execute_Test, ShouldExecuteStdwInstructionSuccess){
     u64 code = 0x7a50004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],64);
}

TEST(VM_Execute_Test, ShouldExecuteStxwInstructionSuccess){
     u64 code = 0x6354004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STXW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 35;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],35);
}

TEST(VM_Execute_Test, ShouldExecuteStxhInstructionSuccess){
     u64 code = 0x6b54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STXH);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 35;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],35);
}

TEST(VM_Execute_Test, ShouldExecuteStxbInstructionSuccess){
     u64 code = 0x7354004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STXB);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 35;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],35);
}

TEST(VM_Execute_Test, ShouldExecuteStxdwInstructionSuccess){
     u64 code = 0x7b54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, STXDW);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister, 0x4);
     ASSERT_EQ(instruction.offset,64);
     vm_init(vm, 100);
     vm.regs[0x5] = 10;
     vm.regs[0x4] = 35;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.memory[74],35);
}

/**
 * branch instructions
 */

TEST(VM_Execute_Test, ShouldExecuteJaInstructionSuccess){
     u64 code = 0x0500004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JA);
     ASSERT_EQ(instruction.offset,64);
     vm_init(vm, 100);
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJeqImmInstructionSuccess){
     u64 code = 0x1550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JEQ_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJeqRegInstructionSuccess){
     u64 code = 0x1d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JEQ_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJgtImmInstructionSuccess){
     u64 code = 0x2550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JGT_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x41;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJgtRegInstructionSuccess){
     u64 code = 0x2d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JGT_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x41;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJgeImmInstructionSuccess){
     u64 code = 0x3550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JGE_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x41;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJgeRegInstructionSuccess){
     u64 code = 0x3d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JGE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x41;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJltImmInstructionSuccess){
     u64 code = 0xa550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JLT_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x39;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJltRegInstructionSuccess){
     u64 code = 0xad54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JLT_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x39;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJleImmInstructionSuccess){
     u64 code = 0xb550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JLE_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x39;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJleRegInstructionSuccess){
     u64 code = 0xbd54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JLE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x39;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsetImmInstructionSuccess){
     u64 code = 0x4550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSET_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsetRegInstructionSuccess){
     u64 code = 0x4d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSET_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJneImmInstructionSuccess){
     u64 code = 0x5550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JNE_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x20;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJneRegInstructionSuccess){
     u64 code = 0x5d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JNE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x20;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsgtImmInstructionSuccess){
     u64 code = 0x6550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSGT_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x50;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsgtRegInstructionSuccess){
     u64 code = 0x6d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSGT_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x20;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsgeImmInstructionSuccess){
     u64 code = 0x7550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSGE_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsgeRegInstructionSuccess){
     u64 code = 0x7d54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSGE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsltImmInstructionSuccess){
     u64 code = 0xc550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSLT_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x20;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsltRegInstructionSuccess){
     u64 code = 0xcd54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSLT_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x20;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsleImmInstructionSuccess){
     u64 code = 0xd550004000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSLE_IMM);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.offset,64);
     ASSERT_EQ(instruction.immediate, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteJsleRegInstructionSuccess){
     u64 code = 0xdd54004000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, JSLE_REG);
     ASSERT_EQ(instruction.destRegister, 0x05);
     ASSERT_EQ(instruction.sourceRegister,0x04);
     ASSERT_EQ(instruction.offset, 64);
     vm_init(vm, 100);
     vm.regs[0x5] = 0x40;
     vm.regs[0x4] = 0x40;
     vm_execute(vm, instruction);
     ASSERT_EQ(vm.pc,64);
}

TEST(VM_Execute_Test, ShouldExecuteCallImmInstructionSuccess){
     u64 code = 0x8500000000000040;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, CALL_IMM);
     ASSERT_EQ(instruction.immediate, 64);
}

TEST(VM_Execute_Test, ShouldExecuteExitInstructionSuccess){
     u64 code = 0x9500000000000000;
     VM_t vm;
     BPFInstruction_t instruction =  vm_decode_code(vm, code);
     ASSERT_EQ(instruction.opcode, EXIT);
}