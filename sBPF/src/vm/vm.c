//
// Created by XingfengYang on 2020/5/29.
//

#include "../../include/vm/vm.h"
#include "../../include/vm/hashmap.h"
#include <stdio.h>
#include <malloc.h>
#include <endian.h>

bool is_little_endion() {
    u16 usFlag = 1;
    return *((u8 *) &usFlag) == 1;
}

#define ADD_HANDLER(INS) handlers[INS] = *(vm_handler_##INS)
void (*handlers[0xFF])(VM_t vm, BPFInstruction_t instruction);
HashMap_t inKernelFuncWrapperMap;
HashMapIterator_t wrapperFuncIterator;

int (*wrapperFunc)(VM_t vm);

void vm_handler_ADD_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ADD_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_SUB_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_SUB_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MUL_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MUL_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_DIV_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_DIV_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_OR_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_OR_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_AND_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_AND_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LSH_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LSH_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_RSH_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_RSH_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_NEG_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOD_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOD_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_XOR_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_XOR_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOV_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOV_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ARSH_IMM_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ARSH_REG_64(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ADD_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ADD_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_SUB_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_SUB_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MUL_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MUL_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_DIV_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_DIV_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_OR_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_OR_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_AND_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_AND_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LSH_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LSH_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_RSH_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_RSH_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_NEG_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOD_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOD_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_XOR_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_XOR_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOV_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_MOV_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ARSH_IMM_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_ARSH_REG_32(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_BE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDABSW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDABSH(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDABSB(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDABSDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDINDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDINDH(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDINDB(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDINDDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDXW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDXH(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDXB(VM_t vm, BPFInstruction_t instruction);

void vm_handler_LDXDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STH(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STB(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STXW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STXH(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STXB(VM_t vm, BPFInstruction_t instruction);

void vm_handler_STXDW(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JA(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JEQ_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JEQ_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JGT_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JGT_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JGE_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JGE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JLT_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JLT_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JLE_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JLE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSET_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSET_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JNE_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JNE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSGT_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSGT_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSGE_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSGE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSLT_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSLT_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSLE_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_JSLE_REG(VM_t vm, BPFInstruction_t instruction);

void vm_handler_CALL_IMM(VM_t vm, BPFInstruction_t instruction);

void vm_handler_EXIT(VM_t vm, BPFInstruction_t instruction);


bool s32Equal(void *key1,void * key2){
    int uKey1 = *(int *)key1;
    int uKey2 = *(int *)key2;
    return uKey1==uKey2; 
}

int s32HashCode(HashMap_t hashMap, void *key){
    int uKey = *(int *)key;
    if(uKey < 0){
        return -uKey % hashMap->listSize;
    }
    return uKey % hashMap->listSize;
}

int WRAPPER_print(VM_t vm){
    printf("Wrapper print invoked.\n");
    return 0;
}

void setInstructionhandler(){
    ADD_HANDLER(ADD_IMM_64);    ADD_HANDLER(ADD_IMM_64);    ADD_HANDLER(ADD_REG_64);    ADD_HANDLER(SUB_IMM_64);    ADD_HANDLER(SUB_REG_64);
    ADD_HANDLER(MUL_IMM_64);    ADD_HANDLER(MUL_REG_64);    ADD_HANDLER(DIV_IMM_64);    ADD_HANDLER(DIV_REG_64);    ADD_HANDLER(OR_IMM_64);
    ADD_HANDLER(OR_REG_64);     ADD_HANDLER(AND_IMM_64);    ADD_HANDLER(AND_REG_64);    ADD_HANDLER(LSH_IMM_64);    ADD_HANDLER(LSH_REG_64);
    ADD_HANDLER(RSH_IMM_64);    ADD_HANDLER(RSH_REG_64);    ADD_HANDLER(NEG_REG_64);    ADD_HANDLER(MOD_IMM_64);    ADD_HANDLER(MOD_REG_64);
    ADD_HANDLER(XOR_IMM_64);    ADD_HANDLER(XOR_REG_64);    ADD_HANDLER(MOV_IMM_64);    ADD_HANDLER(MOV_REG_64);    ADD_HANDLER(ARSH_IMM_64);
    ADD_HANDLER(ARSH_REG_64);   ADD_HANDLER(ADD_IMM_32);    ADD_HANDLER(ADD_REG_32);    ADD_HANDLER(SUB_IMM_32);    ADD_HANDLER(SUB_REG_32);
    ADD_HANDLER(MUL_IMM_32);    ADD_HANDLER(MUL_REG_32);    ADD_HANDLER(DIV_IMM_32);    ADD_HANDLER(DIV_REG_32);    ADD_HANDLER(OR_IMM_32);
    ADD_HANDLER(OR_REG_32);     ADD_HANDLER(AND_IMM_32);    ADD_HANDLER(AND_REG_32);    ADD_HANDLER(LSH_IMM_32);    ADD_HANDLER(LSH_REG_32);
    ADD_HANDLER(RSH_IMM_32);    ADD_HANDLER(RSH_REG_32);    ADD_HANDLER(NEG_REG_32);    ADD_HANDLER(MOD_IMM_32);    ADD_HANDLER(MOD_REG_32);
    ADD_HANDLER(XOR_IMM_32);    ADD_HANDLER(XOR_REG_32);    ADD_HANDLER(MOV_IMM_32);    ADD_HANDLER(MOV_REG_32);    ADD_HANDLER(ARSH_IMM_32);
    ADD_HANDLER(ARSH_REG_32);   ADD_HANDLER(LE_REG);        ADD_HANDLER(BE_REG);        ADD_HANDLER(LDDW);          ADD_HANDLER(LDABSW);
    ADD_HANDLER(LDABSH);        ADD_HANDLER(LDABSB);        ADD_HANDLER(LDABSDW);       ADD_HANDLER(LDINDW);        ADD_HANDLER(LDINDH);
    ADD_HANDLER(LDINDB);        ADD_HANDLER(LDINDDW);       ADD_HANDLER(LDXW);          ADD_HANDLER(LDXH);          ADD_HANDLER(LDXB);
    ADD_HANDLER(LDXDW);         ADD_HANDLER(STW);           ADD_HANDLER(STH);           ADD_HANDLER(STB);           ADD_HANDLER(STDW);
    ADD_HANDLER(STXW);          ADD_HANDLER(STXH);          ADD_HANDLER(STXB);          ADD_HANDLER(STXDW);         ADD_HANDLER(JA);
    ADD_HANDLER(JEQ_IMM);       ADD_HANDLER(JEQ_REG);       ADD_HANDLER(JGT_IMM);       ADD_HANDLER(JGT_REG);       ADD_HANDLER(JGE_IMM);
    ADD_HANDLER(JGE_REG);       ADD_HANDLER(JLT_IMM);       ADD_HANDLER(JLT_REG);       ADD_HANDLER(JLE_IMM);       ADD_HANDLER(JLE_REG);
    ADD_HANDLER(JSET_IMM);      ADD_HANDLER(JSET_REG);      ADD_HANDLER(JNE_IMM);       ADD_HANDLER(JNE_REG);       ADD_HANDLER(JSGT_IMM);
    ADD_HANDLER(JSGT_REG);      ADD_HANDLER(JSGE_IMM);      ADD_HANDLER(JSGE_REG);      ADD_HANDLER(JSLT_IMM);      ADD_HANDLER(JSLT_REG);
    ADD_HANDLER(JSLE_IMM);      ADD_HANDLER(JSLE_REG);      ADD_HANDLER(CALL_IMM);      ADD_HANDLER(EXIT);
}

void setInKernelWrapper(){
    int* key = (int*)malloc(sizeof(int));
    *key = 1;
    inKernelFuncWrapperMap->putFunc(inKernelFuncWrapperMap,(void*)key,(void*)&WRAPPER_print);
}

void vm_init(VM_t vm, u32 memorySize) {
    if (memorySize > 65535) {
        // exceed max memory, vm exited.
    }
    vm->memory = (u64 *) malloc(memorySize * sizeof(u64));
    vm->memorySize = memorySize;

    vm->regs[0] = 0;
    vm->regs[1] = 0;
    vm->regs[2] = 0;
    vm->regs[3] = 0;
    vm->regs[4] = 0;
    vm->regs[5] = 0;
    vm->regs[6] = 0;
    vm->regs[7] = 0;
    vm->regs[8] = 0;
    vm->regs[9] = 0;
    vm->regs[10] = 0;

    vm->pc = 0;
    vm->sp = 0;

    setInstructionhandler();

    inKernelFuncWrapperMap = createHashMap(s32HashCode,s32Equal);
    wrapperFuncIterator = createHashMapIterator(inKernelFuncWrapperMap);

    setInKernelWrapper();
}



bool vm_verify_code(VM_t vm, u64 code) {
    return true;
}

void vm_load_program(VM_t vm, u64 *program) {
    int index = 0;
    while (*program) {
        if (!vm_verify_code(vm, *program)) {
            break;
        }
        vm->memory[index] = *program;
        index++;
        program++;
    }
}

void vm_install_program(VM_t vm, char *elfFile){
    
}

u64 vm_fetch_code(VM_t vm) {
    u64 code = vm->memory[vm->pc];
    vm->pc++;
    return code;
}

BPFInstruction_t vm_decode_code(VM_t vm, u64 code) {
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

    BPFInstruction_t instruction = {
            .opcode = opCode,
            .destRegister = destRegister,
            .sourceRegister = sourceRegister,
            .offset = offset,
            .immediate = immediate,
    };

    return instruction;
}

void vm_execute(VM_t vm, BPFInstruction_t instruction) {
    handlers[instruction.opcode](vm, instruction);
}

void vm_run(VM_t vm) {
    while(vm->pc < vm->memorySize){
        u64 code = vm_fetch_code(vm);
        BPFInstruction_t ins =  vm_decode_code(vm,code);
        // vm_print_instruction(vm, ins);
        vm_execute(vm, ins);
    }
}

void vm_handler_ADD_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] + instruction.immediate;
}

void vm_handler_ADD_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] + vm->regs[instruction.sourceRegister];
}

void vm_handler_SUB_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] - instruction.immediate;
}

void vm_handler_SUB_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] - vm->regs[instruction.sourceRegister];
}

void vm_handler_MUL_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] * instruction.immediate;
}

void vm_handler_MUL_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] * vm->regs[instruction.sourceRegister];
}

void vm_handler_DIV_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 0) {
        exit(0);
    }
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] / instruction.immediate;
}

void vm_handler_DIV_REG_64(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.sourceRegister] == 0) {
        exit(0);
    }
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] / vm->regs[instruction.sourceRegister];
}

void vm_handler_OR_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] | instruction.immediate;
}

void vm_handler_OR_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] | vm->regs[instruction.sourceRegister];
}

void vm_handler_AND_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] & instruction.immediate;
}

void vm_handler_AND_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] & vm->regs[instruction.sourceRegister];
}

void vm_handler_LSH_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] << instruction.immediate;
}

void vm_handler_LSH_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] << vm->regs[instruction.sourceRegister];
}

void vm_handler_RSH_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
}

void vm_handler_RSH_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
}

void vm_handler_NEG_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = -vm->regs[instruction.destRegister];
}

void vm_handler_MOD_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] % instruction.immediate;
}

void vm_handler_MOD_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] % vm->regs[instruction.sourceRegister];
}

void vm_handler_XOR_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] ^ instruction.immediate;
}

void vm_handler_XOR_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] ^ vm->regs[instruction.sourceRegister];
}

void vm_handler_MOV_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_MOV_REG_64(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.sourceRegister];
}

void vm_handler_ARSH_IMM_64(VM_t vm, BPFInstruction_t instruction) {
    if ((vm->regs[instruction.destRegister] >> 63) & 0x1) { // signed
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
        vm->regs[instruction.destRegister] |= ((u64)(1<<instruction.immediate)-1)<<(64-instruction.immediate); // set higher bit to 1
    }else{
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
    }
}

void vm_handler_ARSH_REG_64(VM_t vm, BPFInstruction_t instruction) {
    if ((vm->regs[instruction.destRegister] >> 63) & 0x1) { // signed
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
        vm->regs[instruction.destRegister] |= ((u64)(1<<vm->regs[instruction.sourceRegister])-1)<<(64-vm->regs[instruction.sourceRegister]); // set higher bit to 1
    }else{
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
    }
}

void vm_handler_ADD_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] + instruction.immediate;
}

void vm_handler_ADD_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] + vm->regs[instruction.sourceRegister];
}

void vm_handler_SUB_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] - instruction.immediate;
}

void vm_handler_SUB_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] - vm->regs[instruction.sourceRegister];
}

void vm_handler_MUL_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] * instruction.immediate;
}

void vm_handler_MUL_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] * vm->regs[instruction.sourceRegister];
}

void vm_handler_DIV_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 0) {
        exit(0);
    }
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] / instruction.immediate;
}

void vm_handler_DIV_REG_32(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.sourceRegister] == 0) {
        exit(0);
    }
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] / vm->regs[instruction.sourceRegister];
}

void vm_handler_OR_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] | instruction.immediate;
}

void vm_handler_OR_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] | vm->regs[instruction.sourceRegister];
}

void vm_handler_AND_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] & instruction.immediate;
}

void vm_handler_AND_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] & vm->regs[instruction.sourceRegister];
}

void vm_handler_LSH_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] << instruction.immediate;
}

void vm_handler_LSH_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] << vm->regs[instruction.sourceRegister];
}

void vm_handler_RSH_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
}

void vm_handler_RSH_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
}

void vm_handler_NEG_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = -vm->regs[instruction.destRegister];
}

void vm_handler_MOD_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] % instruction.immediate;
}

void vm_handler_MOD_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] % vm->regs[instruction.sourceRegister];
}

void vm_handler_XOR_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] ^ instruction.immediate;
}

void vm_handler_XOR_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] ^ vm->regs[instruction.sourceRegister];
}

void vm_handler_MOV_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_MOV_REG_32(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = vm->regs[instruction.sourceRegister];
}

void vm_handler_ARSH_IMM_32(VM_t vm, BPFInstruction_t instruction) {
    if ((vm->regs[instruction.destRegister] >> 31) & 0x1) { // signed
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
        vm->regs[instruction.destRegister] |= ((1<<instruction.immediate)-1)<<(32-instruction.immediate); // set higher bit to 1
    }else{
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> instruction.immediate;
    }
}

void vm_handler_ARSH_REG_32(VM_t vm, BPFInstruction_t instruction) {
    if ((vm->regs[instruction.destRegister] >> 31) & 0x1) { // signed
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
        vm->regs[instruction.destRegister] |= ((1<<vm->regs[instruction.sourceRegister])-1)<<(32-vm->regs[instruction.sourceRegister]); // set higher bit to 1
    }else{
        vm->regs[instruction.destRegister] = vm->regs[instruction.destRegister] >> vm->regs[instruction.sourceRegister];
    }
}

void vm_handler_LE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 16) {
        vm->regs[instruction.destRegister] = htole16(vm->regs[instruction.destRegister]);
    }
    if (instruction.immediate == 32) {
        vm->regs[instruction.destRegister] = htole32(vm->regs[instruction.destRegister]);
    }
    if (instruction.immediate == 64) {
        vm->regs[instruction.destRegister] = htole64(vm->regs[instruction.destRegister]);
    }
}

void vm_handler_BE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (instruction.immediate == 16) {
        vm->regs[instruction.destRegister] = htobe16(vm->regs[instruction.destRegister]);
    }
    if (instruction.immediate == 32) {
        vm->regs[instruction.destRegister] = htobe32(vm->regs[instruction.destRegister]);
    }
    if (instruction.immediate == 64) {
        vm->regs[instruction.destRegister] = htobe64(vm->regs[instruction.destRegister]);
    }
}

void vm_handler_LDDW(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = instruction.immediate;
}

void vm_handler_LDABSW(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSH(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSB(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDABSDW(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDW(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDH(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDB(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDINDDW(VM_t vm, BPFInstruction_t instruction) {

}

void vm_handler_LDXW(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = (u32) vm->memory[vm->regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXH(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = (u16) vm->memory[vm->regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXB(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = (u8) vm->memory[vm->regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_LDXDW(VM_t vm, BPFInstruction_t instruction) {
    vm->regs[instruction.destRegister] = (u64) vm->memory[vm->regs[instruction.sourceRegister] + instruction.offset];
}

void vm_handler_STW(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u32) instruction.immediate;
}

void vm_handler_STH(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u16) instruction.immediate;
}

void vm_handler_STB(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u8) instruction.immediate;
}

void vm_handler_STDW(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u64) instruction.immediate;
}

void vm_handler_STXW(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u32) vm->regs[instruction.sourceRegister];
}

void vm_handler_STXH(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u16) vm->regs[instruction.sourceRegister];
}

void vm_handler_STXB(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u8) vm->regs[instruction.sourceRegister];
}

void vm_handler_STXDW(VM_t vm, BPFInstruction_t instruction) {
    vm->memory[vm->regs[instruction.destRegister] + instruction.offset] = (u64) vm->regs[instruction.sourceRegister];
}

void vm_handler_JA(VM_t vm, BPFInstruction_t instruction) {
    vm->pc += instruction.offset;
}

void vm_handler_JEQ_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] == instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JEQ_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] == vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JGT_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] > instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JGT_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] > vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JGE_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] >= instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JGE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] >= vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JLT_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] < instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JLT_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] < vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JLE_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] <= instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JLE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] <= vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSET_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] & instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSET_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] & vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JNE_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] != instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JNE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] != vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSGT_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] > (s32) instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSGT_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] > (s32) vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSGE_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] >= (s32) instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSGE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] >= (s32) vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSLT_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] < (s32) instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSLT_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] < (s32) vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSLE_IMM(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] <= (s32) instruction.immediate) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_JSLE_REG(VM_t vm, BPFInstruction_t instruction) {
    if (vm->regs[instruction.destRegister] <= (s32) vm->regs[instruction.sourceRegister]) {
        vm->pc += instruction.offset;
    }
}

void vm_handler_CALL_IMM(VM_t vm, BPFInstruction_t instruction) {
    void * wrapper = inKernelFuncWrapperMap->getFunc(inKernelFuncWrapperMap,(void*)&instruction.immediate);
    ((int(*)(VM_t))wrapper)(vm);
}

void vm_handler_EXIT(VM_t vm, BPFInstruction_t instruction) {
    free(vm->memory);
    exit(vm->regs[0]);
}

void vm_print_instruction(VM_t vm, BPFInstruction_t instruction) {
    printf("{\n\topcode: %d\n", instruction.opcode);
    printf("\tdestRegister: %d\n", instruction.destRegister);
    printf("\tsourceRegister: %d\n", instruction.sourceRegister);
    printf("\toffset: %d\n", instruction.offset);
    printf("\timmediate: %d\n}\n", instruction.immediate);
}