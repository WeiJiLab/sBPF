//
// Created by XingfengYang on 2020/5/29.
//

#include "../include/instruction.h"
#include <stdio.h>
#include <memory>
#include <endian.h>

bool is_little_endion() {
    u16 usFlag = 1;
    return *((u8 *) &usFlag) == 1;
}

#define ADD_HANDLER(VM, INS) VM.handlers[INS] = *(vm_handler_##INS)

void vm_handler_ADD_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ADD_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_SUB_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_SUB_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MUL_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MUL_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_DIV_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_DIV_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_OR_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_OR_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_AND_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_AND_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LSH_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LSH_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_RSH_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_RSH_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_NEG_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOD_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOD_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_XOR_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_XOR_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOV_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOV_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ARSH_IMM_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ARSH_REG_64(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ADD_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ADD_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_SUB_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_SUB_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MUL_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MUL_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_DIV_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_DIV_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_OR_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_OR_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_AND_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_AND_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LSH_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LSH_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_RSH_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_RSH_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_NEG_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOD_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOD_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_XOR_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_XOR_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOV_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_MOV_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ARSH_IMM_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_ARSH_REG_32(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_BE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDABSW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDABSH(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDABSB(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDABSDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDINDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDINDH(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDINDB(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDINDDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDXW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDXH(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDXB(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_LDXDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STH(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STB(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STXW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STXH(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STXB(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_STXDW(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JA(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JEQ_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JEQ_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JGT_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JGT_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JGE_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JGE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JLT_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JLT_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JLE_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JLE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSET_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSET_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JNE_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JNE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSGT_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSGT_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSGE_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSGE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSLT_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSLT_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSLE_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_JSLE_REG(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_CALL_IMM(VM_t &vm, BPFInstruction_t instruction);

void vm_handler_EXIT(VM_t &vm, BPFInstruction_t instruction);

void vm_init(VM_t &vm, u32 memorySize) {
    if (memorySize > 65535) {
        // exceed max memory, vm exited.
    }
    vm.memory = (u64 *) malloc(memorySize * sizeof(u64));

    vm.regs[0] = 0;
    vm.regs[1] = 0;
    vm.regs[2] = 0;
    vm.regs[3] = 0;
    vm.regs[4] = 0;
    vm.regs[5] = 0;
    vm.regs[6] = 0;
    vm.regs[7] = 0;
    vm.regs[8] = 0;
    vm.regs[9] = 0;
    vm.regs[10] = 0;

    vm.pc = 0;
    vm.sp = 0;

    ADD_HANDLER(vm, ADD_IMM_64);
    ADD_HANDLER(vm, ADD_IMM_64);
    ADD_HANDLER(vm, ADD_REG_64);
    ADD_HANDLER(vm, SUB_IMM_64);
    ADD_HANDLER(vm, SUB_REG_64);
    ADD_HANDLER(vm, MUL_IMM_64);
    ADD_HANDLER(vm, MUL_REG_64);
    ADD_HANDLER(vm, DIV_IMM_64);
    ADD_HANDLER(vm, DIV_REG_64);
    ADD_HANDLER(vm, OR_IMM_64);
    ADD_HANDLER(vm, OR_REG_64);
    ADD_HANDLER(vm, AND_IMM_64);
    ADD_HANDLER(vm, AND_REG_64);
    ADD_HANDLER(vm, LSH_IMM_64);
    ADD_HANDLER(vm, LSH_REG_64);
    ADD_HANDLER(vm, RSH_IMM_64);
    ADD_HANDLER(vm, RSH_REG_64);
    ADD_HANDLER(vm, NEG_REG_64);
    ADD_HANDLER(vm, MOD_IMM_64);
    ADD_HANDLER(vm, MOD_REG_64);
    ADD_HANDLER(vm, XOR_IMM_64);
    ADD_HANDLER(vm, XOR_REG_64);
    ADD_HANDLER(vm, MOV_IMM_64);
    ADD_HANDLER(vm, MOV_REG_64);
    ADD_HANDLER(vm, ARSH_IMM_64);
    ADD_HANDLER(vm, ARSH_REG_64);
    ADD_HANDLER(vm, ADD_IMM_32);
    ADD_HANDLER(vm, ADD_REG_32);
    ADD_HANDLER(vm, SUB_IMM_32);
    ADD_HANDLER(vm, SUB_REG_32);
    ADD_HANDLER(vm, MUL_IMM_32);
    ADD_HANDLER(vm, MUL_REG_32);
    ADD_HANDLER(vm, DIV_IMM_32);
    ADD_HANDLER(vm, DIV_REG_32);
    ADD_HANDLER(vm, OR_IMM_32);
    ADD_HANDLER(vm, OR_REG_32);
    ADD_HANDLER(vm, AND_IMM_32);
    ADD_HANDLER(vm, AND_REG_32);
    ADD_HANDLER(vm, LSH_IMM_32);
    ADD_HANDLER(vm, LSH_REG_32);
    ADD_HANDLER(vm, RSH_IMM_32);
    ADD_HANDLER(vm, RSH_REG_32);
    ADD_HANDLER(vm, NEG_REG_32);
    ADD_HANDLER(vm, MOD_IMM_32);
    ADD_HANDLER(vm, MOD_REG_32);
    ADD_HANDLER(vm, XOR_IMM_32);
    ADD_HANDLER(vm, XOR_REG_32);
    ADD_HANDLER(vm, MOV_IMM_32);
    ADD_HANDLER(vm, MOV_REG_32);
    ADD_HANDLER(vm, ARSH_IMM_32);
    ADD_HANDLER(vm, ARSH_REG_32);
    ADD_HANDLER(vm, LE_REG);
    ADD_HANDLER(vm, BE_REG);
    ADD_HANDLER(vm, LDDW);
    ADD_HANDLER(vm, LDABSW);
    ADD_HANDLER(vm, LDABSH);
    ADD_HANDLER(vm, LDABSB);
    ADD_HANDLER(vm, LDABSDW);
    ADD_HANDLER(vm, LDINDW);
    ADD_HANDLER(vm, LDINDH);
    ADD_HANDLER(vm, LDINDB);
    ADD_HANDLER(vm, LDINDDW);
    ADD_HANDLER(vm, LDXW);
    ADD_HANDLER(vm, LDXH);
    ADD_HANDLER(vm, LDXB);
    ADD_HANDLER(vm, LDXDW);
    ADD_HANDLER(vm, STW);
    ADD_HANDLER(vm, STH);
    ADD_HANDLER(vm, STB);
    ADD_HANDLER(vm, STDW);
    ADD_HANDLER(vm, STXW);
    ADD_HANDLER(vm, STXH);
    ADD_HANDLER(vm, STXB);
    ADD_HANDLER(vm, STXDW);
    ADD_HANDLER(vm, JA);
    ADD_HANDLER(vm, JEQ_IMM);
    ADD_HANDLER(vm, JEQ_REG);
    ADD_HANDLER(vm, JGT_IMM);
    ADD_HANDLER(vm, JGT_REG);
    ADD_HANDLER(vm, JGE_IMM);
    ADD_HANDLER(vm, JGE_REG);
    ADD_HANDLER(vm, JLT_IMM);
    ADD_HANDLER(vm, JLT_REG);
    ADD_HANDLER(vm, JLE_IMM);
    ADD_HANDLER(vm, JLE_REG);
    ADD_HANDLER(vm, JSET_IMM);
    ADD_HANDLER(vm, JSET_REG);
    ADD_HANDLER(vm, JNE_IMM);
    ADD_HANDLER(vm, JNE_REG);
    ADD_HANDLER(vm, JSGT_IMM);
    ADD_HANDLER(vm, JSGT_REG);
    ADD_HANDLER(vm, JSGE_IMM);
    ADD_HANDLER(vm, JSGE_REG);
    ADD_HANDLER(vm, JSLT_IMM);
    ADD_HANDLER(vm, JSLT_REG);
    ADD_HANDLER(vm, JSLE_IMM);
    ADD_HANDLER(vm, JSLE_REG);
    ADD_HANDLER(vm, CALL_IMM);
    ADD_HANDLER(vm, EXIT);
}

bool vm_verify_code(VM_t &vm, u64 code) {
    return true;
}

void vm_load_program(VM_t &vm, u64 *program) {
    while (*program) {
        if (!vm_verify_code(vm, *program)) {
            break;
        }

        program++;
    }
}

u64 vm_fetch_code(VM_t &vm, u32 pc) {
    return vm.memory[pc];
    pc++;
}

BPFInstruction_t vm_decode_code(VM_t &vm, u64 code) {
    u8 opCode = 0;
    u8 destRegister = 0;
    u8 sourceRegister = 0;
    s16 offset = 0;
    s32 immediate = 0;

    if (((code >> 32) & 0xFFFFFFFF) == 0) { // 32 bits
        opCode = (code >> 24) & 0xFF;
        destRegister = (code >> 20) & 0xF;
        sourceRegister = (code >> 16) & 0xF;
        immediate = code & 0xFFFF;
    } else {
        opCode = (code >> 56) & 0xFF;
        destRegister = (code >> 52) & 0xF;
        sourceRegister = (code >> 48) & 0xF;
        offset = (code >> 32) & 0xFFFF;
        immediate = code & 0xFFFFFFFF;
    }

    return {
            .opcode = opCode,
            .destRegister = destRegister,
            .sourceRegister = sourceRegister,
            .offset = offset,
            .immediate = immediate,
    };
}

void vm_execute(VM_t &vm, BPFInstruction_t instruction) {
    vm.handlers[instruction.opcode](vm, instruction);
}

void vm_run(VM_t &vm) {

}

void vm_handler_ADD_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] + instruction.immediate;
}

void vm_handler_ADD_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] + vm.regs[instruction.sourceRegister];
}

void vm_handler_SUB_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] - instruction.immediate;
}

void vm_handler_SUB_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] - vm.regs[instruction.sourceRegister];
}

void vm_handler_MUL_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] * instruction.immediate;
}

void vm_handler_MUL_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] * vm.regs[instruction.sourceRegister];
}

void vm_handler_DIV_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 0) {
        exit(0);
    }
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] / instruction.immediate;
}

void vm_handler_DIV_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.sourceRegister] == 0) {
        exit(0);
    }
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] / vm.regs[instruction.sourceRegister];
}

void vm_handler_OR_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] | instruction.immediate;
}

void vm_handler_OR_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] | vm.regs[instruction.sourceRegister];
}

void vm_handler_AND_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] & instruction.immediate;
}

void vm_handler_AND_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] & vm.regs[instruction.sourceRegister];
}

void vm_handler_LSH_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] << instruction.immediate;
}

void vm_handler_LSH_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] << vm.regs[instruction.sourceRegister];
}

void vm_handler_RSH_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> instruction.immediate;
}

void vm_handler_RSH_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> vm.regs[instruction.sourceRegister];
}

void vm_handler_NEG_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = -vm.regs[instruction.destRegister];
}

void vm_handler_MOD_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] % instruction.immediate;
}

void vm_handler_MOD_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] % vm.regs[instruction.sourceRegister];
}

void vm_handler_XOR_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] ^ instruction.immediate;
}

void vm_handler_XOR_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] ^ vm.regs[instruction.sourceRegister];
}

void vm_handler_MOV_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_MOV_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.sourceRegister];
}

void vm_handler_ARSH_IMM_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> instruction.immediate;
    if ((vm.regs[instruction.destRegister] >> 65) && 0x1) { // signed
        vm.regs[instruction.destRegister] |= 0xA000000000000000; // set the highest bit to 1
    }
}

void vm_handler_ARSH_REG_64(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> vm.regs[instruction.sourceRegister];
    if ((vm.regs[instruction.destRegister] >> 65) && 0x1) { // signed
        vm.regs[instruction.destRegister] |= 0xA000000000000000; // set the highest bit to 1
    }
}

void vm_handler_ADD_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] + instruction.immediate;
}

void vm_handler_ADD_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] + vm.regs[instruction.sourceRegister];
}

void vm_handler_SUB_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] - instruction.immediate;
}

void vm_handler_SUB_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] - vm.regs[instruction.sourceRegister];
}

void vm_handler_MUL_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] * instruction.immediate;
}

void vm_handler_MUL_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] * vm.regs[instruction.sourceRegister];
}

void vm_handler_DIV_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 0) {
        exit(0);
    }
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] / instruction.immediate;
}

void vm_handler_DIV_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.sourceRegister] == 0) {
        exit(0);
    }
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] / vm.regs[instruction.sourceRegister];
}

void vm_handler_OR_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] | instruction.immediate;
}

void vm_handler_OR_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] | vm.regs[instruction.sourceRegister];
}

void vm_handler_AND_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] & instruction.immediate;
}

void vm_handler_AND_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] & vm.regs[instruction.sourceRegister];
}

void vm_handler_LSH_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] << instruction.immediate;
}

void vm_handler_LSH_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] << vm.regs[instruction.sourceRegister];
}

void vm_handler_RSH_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> instruction.immediate;
}

void vm_handler_RSH_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> vm.regs[instruction.sourceRegister];
}

void vm_handler_NEG_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = -vm.regs[instruction.destRegister];
}

void vm_handler_MOD_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] % instruction.immediate;
}

void vm_handler_MOD_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] % vm.regs[instruction.sourceRegister];
}

void vm_handler_XOR_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] ^ instruction.immediate;
}

void vm_handler_XOR_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] ^ vm.regs[instruction.sourceRegister];
}

void vm_handler_MOV_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_MOV_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.sourceRegister];
}

void vm_handler_ARSH_IMM_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> instruction.immediate;
    if ((vm.regs[instruction.destRegister] >> 31) && 0x1) { // signed
        vm.regs[instruction.destRegister] |= 0xA0000000; // set the highest bit to 1
    }
}

void vm_handler_ARSH_REG_32(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = vm.regs[instruction.destRegister] >> vm.regs[instruction.sourceRegister];
    if ((vm.regs[instruction.destRegister] >> 31) && 0x1) { // signed
        vm.regs[instruction.destRegister] |= 0xA0000000; // set the highest bit to 1
    }
}

void vm_handler_LE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 16) {
        vm.regs[instruction.destRegister] = htole16(vm.regs[instruction.destRegister]);
    }
    if (instruction.immediate == 32) {
        vm.regs[instruction.destRegister] = htole32(vm.regs[instruction.destRegister]);
    }
    if (instruction.immediate == 64) {
        vm.regs[instruction.destRegister] = htole64(vm.regs[instruction.destRegister]);
    }
}

void vm_handler_BE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 16) {
        vm.regs[instruction.destRegister] = htobe16(vm.regs[instruction.destRegister]);
    }
    if (instruction.immediate == 32) {
        vm.regs[instruction.destRegister] = htobe32(vm.regs[instruction.destRegister]);
    }
    if (instruction.immediate == 64) {
        vm.regs[instruction.destRegister] = htobe64(vm.regs[instruction.destRegister]);
    }
}

void vm_handler_LDDW(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_LDABSW(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSH(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSB(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSDW(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDW(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDH(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDB(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDDW(VM_t &vm, BPFInstruction_t instruction) {

}

void vm_handler_LDXW(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = (u32) vm.memory[vm.regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXH(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = (u16) vm.memory[vm.regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXB(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = (u8) vm.memory[vm.regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXDW(VM_t &vm, BPFInstruction_t instruction) {
    vm.regs[instruction.destRegister] = (u64) vm.memory[vm.regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_STW(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u32) instruction.immediate;
}

void vm_handler_STH(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u16) instruction.immediate;
}

void vm_handler_STB(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u8) instruction.immediate;
}

void vm_handler_STDW(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u64) instruction.immediate;
}

void vm_handler_STXW(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u32) vm.regs[instruction.sourceRegister];
}

void vm_handler_STXH(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u16) vm.regs[instruction.sourceRegister];
}

void vm_handler_STXB(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u8) vm.regs[instruction.sourceRegister];
}

void vm_handler_STXDW(VM_t &vm, BPFInstruction_t instruction) {
    vm.memory[vm.regs[instruction.destRegister] + instruction.offset] = (u64) vm.regs[instruction.sourceRegister];
}

void vm_handler_JA(VM_t &vm, BPFInstruction_t instruction) {
    vm.pc += instruction.offset;
}

void vm_handler_JEQ_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] == instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JEQ_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] == vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JGT_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] > instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JGT_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] > vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JGE_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] >= instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JGE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] >= vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JLT_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] < instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JLT_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] < vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JLE_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] <= instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JLE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] <= vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSET_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] & instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSET_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] & vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JNE_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] != instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JNE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] != vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSGT_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] > (s32) instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSGT_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] > (s32) vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSGE_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] >= (s32) instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSGE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] >= (s32) vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSLT_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] < (s32) instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSLT_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] < (s32) vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSLE_IMM(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] <= (s32) instruction.immediate) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_JSLE_REG(VM_t &vm, BPFInstruction_t instruction) {
    if (vm.regs[instruction.destRegister] <= (s32) vm.regs[instruction.sourceRegister]) {
        vm.pc += instruction.offset;
    }
}

void vm_handler_CALL_IMM(VM_t &vm, BPFInstruction_t instruction) {
    // todo: function call
}

void vm_handler_EXIT(VM_t &vm, BPFInstruction_t instruction) {
    exit(vm.regs[0]);
}

void vm_print_instruction(VM_t &vm, BPFInstruction_t instruction) {
    printf("{\n\topcode: %d\n", instruction.opcode);
    printf("\tdestRegister: %d\n", instruction.destRegister);
    printf("\tsourceRegister: %d\n", instruction.sourceRegister);
    printf("\toffset: %d\n", instruction.offset);
    printf("\timmediate: %d\n}\n", instruction.immediate);
}
