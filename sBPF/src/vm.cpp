//
// Created by XingfengYang on 2020/5/29.
//

#include "../include/instruction.h"
#include <stdio.h>
#include <memory>

#define ADD_HANDLER(INS) vm.handlers[INS] = *(vm_handler_##INS)

VM_t vm;
void vm_handler_ADD_IMM_64(BPFInstruction_t instruction);
void vm_handler_ADD_REG_64(BPFInstruction_t instruction);
void vm_handler_SUB_IMM_64(BPFInstruction_t instruction);
void vm_handler_SUB_REG_64(BPFInstruction_t instruction);
void vm_handler_MUL_IMM_64(BPFInstruction_t instruction);
void vm_handler_MUL_REG_64(BPFInstruction_t instruction);
void vm_handler_DIV_IMM_64(BPFInstruction_t instruction);
void vm_handler_DIV_REG_64(BPFInstruction_t instruction);
void vm_handler_OR_IMM_64(BPFInstruction_t instruction);
void vm_handler_OR_REG_64(BPFInstruction_t instruction);
void vm_handler_AND_IMM_64(BPFInstruction_t instruction);
void vm_handler_AND_REG_64(BPFInstruction_t instruction);
void vm_handler_LSH_IMM_64(BPFInstruction_t instruction);
void vm_handler_LSH_REG_64(BPFInstruction_t instruction);
void vm_handler_RSH_IMM_64(BPFInstruction_t instruction);
void vm_handler_RSH_REG_64(BPFInstruction_t instruction);
void vm_handler_NEG_REG_64(BPFInstruction_t instruction);
void vm_handler_MOD_IMM_64(BPFInstruction_t instruction);
void vm_handler_MOD_REG_64(BPFInstruction_t instruction);
void vm_handler_XOR_IMM_64(BPFInstruction_t instruction);
void vm_handler_XOR_REG_64(BPFInstruction_t instruction);
void vm_handler_MOV_IMM_64(BPFInstruction_t instruction);
void vm_handler_MOV_REG_64(BPFInstruction_t instruction);
void vm_handler_ARSH_IMM_64(BPFInstruction_t instruction);
void vm_handler_ARSH_REG_64(BPFInstruction_t instruction);
void vm_handler_ADD_IMM_32(BPFInstruction_t instruction);
void vm_handler_ADD_REG_32(BPFInstruction_t instruction);
void vm_handler_SUB_IMM_32(BPFInstruction_t instruction);
void vm_handler_SUB_REG_32(BPFInstruction_t instruction);
void vm_handler_MUL_IMM_32(BPFInstruction_t instruction);
void vm_handler_MUL_REG_32(BPFInstruction_t instruction);
void vm_handler_DIV_IMM_32(BPFInstruction_t instruction);
void vm_handler_DIV_REG_32(BPFInstruction_t instruction);
void vm_handler_OR_IMM_32(BPFInstruction_t instruction);
void vm_handler_OR_REG_32(BPFInstruction_t instruction);
void vm_handler_AND_IMM_32(BPFInstruction_t instruction);
void vm_handler_AND_REG_32(BPFInstruction_t instruction);
void vm_handler_LSH_IMM_32(BPFInstruction_t instruction);
void vm_handler_LSH_REG_32(BPFInstruction_t instruction);
void vm_handler_RSH_IMM_32(BPFInstruction_t instruction);
void vm_handler_RSH_REG_32(BPFInstruction_t instruction);
void vm_handler_NEG_REG_32(BPFInstruction_t instruction);
void vm_handler_MOD_IMM_32(BPFInstruction_t instruction);
void vm_handler_MOD_REG_32(BPFInstruction_t instruction);
void vm_handler_XOR_IMM_32(BPFInstruction_t instruction);
void vm_handler_XOR_REG_32(BPFInstruction_t instruction);
void vm_handler_MOV_IMM_32(BPFInstruction_t instruction);
void vm_handler_MOV_REG_32(BPFInstruction_t instruction);
void vm_handler_ARSH_IMM_32(BPFInstruction_t instruction);
void vm_handler_ARSH_REG_32(BPFInstruction_t instruction);
void vm_handler_LE_REG_16(BPFInstruction_t instruction);
void vm_handler_LE_REG_32(BPFInstruction_t instruction);
void vm_handler_LE_REG_64(BPFInstruction_t instruction);
void vm_handler_BE_REG_16(BPFInstruction_t instruction);
void vm_handler_BE_REG_32(BPFInstruction_t instruction);
void vm_handler_BE_REG_64(BPFInstruction_t instruction);
void vm_handler_LDDW(BPFInstruction_t instruction);
void vm_handler_LDABSW(BPFInstruction_t instruction);
void vm_handler_LDABSH(BPFInstruction_t instruction);
void vm_handler_LDABSB(BPFInstruction_t instruction);
void vm_handler_LDABSDW(BPFInstruction_t instruction);
void vm_handler_LDINDW(BPFInstruction_t instruction);
void vm_handler_LDINDH(BPFInstruction_t instruction);
void vm_handler_LDINDB(BPFInstruction_t instruction);
void vm_handler_LDINDDW(BPFInstruction_t instruction);
void vm_handler_LDXW(BPFInstruction_t instruction);
void vm_handler_LDXH(BPFInstruction_t instruction);
void vm_handler_LDXB(BPFInstruction_t instruction);
void vm_handler_LDXDW(BPFInstruction_t instruction);
void vm_handler_STW(BPFInstruction_t instruction);
void vm_handler_STH(BPFInstruction_t instruction);
void vm_handler_STB(BPFInstruction_t instruction);
void vm_handler_STDW(BPFInstruction_t instruction);
void vm_handler_STXW(BPFInstruction_t instruction);
void vm_handler_STXH(BPFInstruction_t instruction);
void vm_handler_STXB(BPFInstruction_t instruction);
void vm_handler_STXDW(BPFInstruction_t instruction);
void vm_handler_JA(BPFInstruction_t instruction);
void vm_handler_JEQ_IMM(BPFInstruction_t instruction);
void vm_handler_JEQ_REG(BPFInstruction_t instruction);
void vm_handler_JGT_IMM(BPFInstruction_t instruction);
void vm_handler_JGT_REG(BPFInstruction_t instruction);
void vm_handler_JGE_IMM(BPFInstruction_t instruction);
void vm_handler_JGE_REG(BPFInstruction_t instruction);
void vm_handler_JLT_IMM(BPFInstruction_t instruction);
void vm_handler_JLT_REG(BPFInstruction_t instruction);
void vm_handler_JLE_IMM(BPFInstruction_t instruction);
void vm_handler_JLE_REG(BPFInstruction_t instruction);
void vm_handler_JSET_IMM(BPFInstruction_t instruction);
void vm_handler_JSET_REG(BPFInstruction_t instruction);
void vm_handler_JNE_IMM(BPFInstruction_t instruction);
void vm_handler_JNE_REG(BPFInstruction_t instruction);
void vm_handler_JSGT_IMM(BPFInstruction_t instruction);
void vm_handler_JSGT_REG(BPFInstruction_t instruction);
void vm_handler_JSGE_IMM(BPFInstruction_t instruction);
void vm_handler_JSGE_REG(BPFInstruction_t instruction);
void vm_handler_JSLT_IMM(BPFInstruction_t instruction);
void vm_handler_JSLT_REG(BPFInstruction_t instruction);
void vm_handler_JSLE_IMM(BPFInstruction_t instruction);
void vm_handler_JSLE_REG(BPFInstruction_t instruction);
void vm_handler_CALL_IMM(BPFInstruction_t instruction);
void vm_handler_EXIT(BPFInstruction_t instruction);

void vm_init(u32 memorySize){
    if(memorySize>65535){
        // exceed max memory, vm exited.
    }
    vm.memory = (u64*)malloc(memorySize*sizeof(u64));
    vm.regs = {
        .r0 = 0,
        .r1 = 0,
        .r2 = 0,
        .r3 = 0,
        .r4 = 0,
        .r5 = 0,
        .r6 = 0,
        .r7 = 0,
        .r8 = 0,
        .r9 = 0,
        .r10 = 0,
    };
    vm.pc = 0;
    vm.sp = 0;

    ADD_HANDLER(ADD_IMM_64);
    ADD_HANDLER(ADD_IMM_64);
    ADD_HANDLER(ADD_REG_64);
    ADD_HANDLER(SUB_IMM_64);
    ADD_HANDLER(SUB_REG_64);
    ADD_HANDLER(MUL_IMM_64);
    ADD_HANDLER(MUL_REG_64);
    ADD_HANDLER(DIV_IMM_64);
    ADD_HANDLER(DIV_REG_64);
    ADD_HANDLER(OR_IMM_64);
    ADD_HANDLER(OR_REG_64);
    ADD_HANDLER(AND_IMM_64);
    ADD_HANDLER(AND_REG_64);
    ADD_HANDLER(LSH_IMM_64);
    ADD_HANDLER(LSH_REG_64);
    ADD_HANDLER(RSH_IMM_64);
    ADD_HANDLER(RSH_REG_64);
    ADD_HANDLER(NEG_REG_64);
    ADD_HANDLER(MOD_IMM_64);
    ADD_HANDLER(MOD_REG_64);
    ADD_HANDLER(XOR_IMM_64);
    ADD_HANDLER(XOR_REG_64);
    ADD_HANDLER(MOV_IMM_64);
    ADD_HANDLER(MOV_REG_64);
    ADD_HANDLER(ARSH_IMM_64);
    ADD_HANDLER(ARSH_REG_64);
    ADD_HANDLER(ADD_IMM_32);
    ADD_HANDLER(ADD_REG_32);
    ADD_HANDLER(SUB_IMM_32);
    ADD_HANDLER(SUB_REG_32);
    ADD_HANDLER(MUL_IMM_32);
    ADD_HANDLER(MUL_REG_32);
    ADD_HANDLER(DIV_IMM_32);
    ADD_HANDLER(DIV_REG_32);
    ADD_HANDLER(OR_IMM_32);
    ADD_HANDLER(OR_REG_32);
    ADD_HANDLER(AND_IMM_32);
    ADD_HANDLER(AND_REG_32);
    ADD_HANDLER(LSH_IMM_32);
    ADD_HANDLER(LSH_REG_32);
    ADD_HANDLER(RSH_IMM_32);
    ADD_HANDLER(RSH_REG_32);
    ADD_HANDLER(NEG_REG_32);
    ADD_HANDLER(MOD_IMM_32);
    ADD_HANDLER(MOD_REG_32);
    ADD_HANDLER(XOR_IMM_32);
    ADD_HANDLER(XOR_REG_32);
    ADD_HANDLER(MOV_IMM_32);
    ADD_HANDLER(MOV_REG_32);
    ADD_HANDLER(ARSH_IMM_32);
    ADD_HANDLER(ARSH_REG_32);
    ADD_HANDLER(LE_REG_16);
    ADD_HANDLER(LE_REG_32);
    ADD_HANDLER(LE_REG_64);
    ADD_HANDLER(BE_REG_16);
    ADD_HANDLER(BE_REG_32);
    ADD_HANDLER(BE_REG_64);
    ADD_HANDLER(LDDW);
    ADD_HANDLER(LDABSW);
    ADD_HANDLER(LDABSH);
    ADD_HANDLER(LDABSB);
    ADD_HANDLER(LDABSDW);
    ADD_HANDLER(LDINDW);
    ADD_HANDLER(LDINDH);
    ADD_HANDLER(LDINDB);
    ADD_HANDLER(LDINDDW);
    ADD_HANDLER(LDXW);
    ADD_HANDLER(LDXH);
    ADD_HANDLER(LDXB);
    ADD_HANDLER(LDXDW);
    ADD_HANDLER(STW);
    ADD_HANDLER(STH);
    ADD_HANDLER(STB);
    ADD_HANDLER(STDW);
    ADD_HANDLER(STXW);
    ADD_HANDLER(STXH);
    ADD_HANDLER(STXB);
    ADD_HANDLER(STXDW);
    ADD_HANDLER(JA);
    ADD_HANDLER(JEQ_IMM);
    ADD_HANDLER(JEQ_REG);
    ADD_HANDLER(JGT_IMM);
    ADD_HANDLER(JGT_REG);
    ADD_HANDLER(JGE_IMM);
    ADD_HANDLER(JGE_REG);
    ADD_HANDLER(JLT_IMM);
    ADD_HANDLER(JLT_REG);
    ADD_HANDLER(JLE_IMM);
    ADD_HANDLER(JLE_REG);
    ADD_HANDLER(JSET_IMM);
    ADD_HANDLER(JSET_REG);
    ADD_HANDLER(JNE_IMM);
    ADD_HANDLER(JNE_REG);
    ADD_HANDLER(JSGT_IMM);
    ADD_HANDLER(JSGT_REG);
    ADD_HANDLER(JSGE_IMM);
    ADD_HANDLER(JSGE_REG);
    ADD_HANDLER(JSLT_IMM);
    ADD_HANDLER(JSLT_REG);
    ADD_HANDLER(JSLE_IMM);
    ADD_HANDLER(JSLE_REG);
    ADD_HANDLER(CALL_IMM);
    ADD_HANDLER(EXIT);
}

void vm_load_program(u64 *program){
    
}

u64 vm_fetch_code(u32 pc){

}

BPFInstruction_t vm_decode_code(u64 code){
    u8  opCode         = 0;
    u8  destRegister   = 0;
    u8  sourceRegister = 0;
    s16 offset         = 0;
    s32 immediate      = 0;

    if(((code >> 32) & 0xFFFFFFFF) == 0){ // 32 bits
        opCode         = (code >> 24) & 0xFF;
        destRegister   = (code >> 20) & 0xF;
        sourceRegister = (code >> 16) & 0xF;
        immediate      = code & 0xFFFF;
    }else{
        opCode         = (code >> 56) & 0xFF;
        destRegister   = (code >> 52) & 0xF;
        sourceRegister = (code >> 48) & 0xF;
        offset         = (code >> 32) & 0xFFFF;
        immediate      = code & 0xFFFFFFFF;
    }

    return {
        .opcode = opCode,
        .destRegister = destRegister,
        .sourceRegister = sourceRegister,
        .offset = offset,
        .immediate = immediate,
    };
}

void vm_execute(){

}

void vm_run(){

}

void vm_handler_ADD_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_ADD_REG_64(BPFInstruction_t instruction){

}

void vm_handler_SUB_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_SUB_REG_64(BPFInstruction_t instruction){

}

void vm_handler_MUL_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_MUL_REG_64(BPFInstruction_t instruction){

}

void vm_handler_DIV_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_DIV_REG_64(BPFInstruction_t instruction){

}

void vm_handler_OR_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_OR_REG_64(BPFInstruction_t instruction){

}

void vm_handler_AND_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_AND_REG_64(BPFInstruction_t instruction){

}

void vm_handler_LSH_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_LSH_REG_64(BPFInstruction_t instruction){

}

void vm_handler_RSH_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_RSH_REG_64(BPFInstruction_t instruction){

}

void vm_handler_NEG_REG_64(BPFInstruction_t instruction){

}

void vm_handler_MOD_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_MOD_REG_64(BPFInstruction_t instruction){

}

void vm_handler_XOR_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_XOR_REG_64(BPFInstruction_t instruction){

}

void vm_handler_MOV_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_MOV_REG_64(BPFInstruction_t instruction){

}

void vm_handler_ARSH_IMM_64(BPFInstruction_t instruction){

}

void vm_handler_ARSH_REG_64(BPFInstruction_t instruction){

}

void vm_handler_ADD_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_ADD_REG_32(BPFInstruction_t instruction){

}

void vm_handler_SUB_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_SUB_REG_32(BPFInstruction_t instruction){

}

void vm_handler_MUL_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_MUL_REG_32(BPFInstruction_t instruction){

}

void vm_handler_DIV_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_DIV_REG_32(BPFInstruction_t instruction){

}

void vm_handler_OR_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_OR_REG_32(BPFInstruction_t instruction){

}

void vm_handler_AND_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_AND_REG_32(BPFInstruction_t instruction){

}

void vm_handler_LSH_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_LSH_REG_32(BPFInstruction_t instruction){

}

void vm_handler_RSH_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_RSH_REG_32(BPFInstruction_t instruction){

}

void vm_handler_NEG_REG_32(BPFInstruction_t instruction){

}

void vm_handler_MOD_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_MOD_REG_32(BPFInstruction_t instruction){

}

void vm_handler_XOR_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_XOR_REG_32(BPFInstruction_t instruction){

}

void vm_handler_MOV_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_MOV_REG_32(BPFInstruction_t instruction){

}

void vm_handler_ARSH_IMM_32(BPFInstruction_t instruction){

}

void vm_handler_ARSH_REG_32(BPFInstruction_t instruction){

}

void vm_handler_LE_REG_16(BPFInstruction_t instruction){

}

void vm_handler_LE_REG_32(BPFInstruction_t instruction){

}

void vm_handler_LE_REG_64(BPFInstruction_t instruction){

}

void vm_handler_BE_REG_16(BPFInstruction_t instruction){

}

void vm_handler_BE_REG_32(BPFInstruction_t instruction){

}

void vm_handler_BE_REG_64(BPFInstruction_t instruction){

}

void vm_handler_LDDW(BPFInstruction_t instruction){

}

void vm_handler_LDABSW(BPFInstruction_t instruction){

}

void vm_handler_LDABSH(BPFInstruction_t instruction){

}

void vm_handler_LDABSB(BPFInstruction_t instruction){

}

void vm_handler_LDABSDW(BPFInstruction_t instruction){

}

void vm_handler_LDINDW(BPFInstruction_t instruction){

}

void vm_handler_LDINDH(BPFInstruction_t instruction){

}

void vm_handler_LDINDB(BPFInstruction_t instruction){

}

void vm_handler_LDINDDW(BPFInstruction_t instruction){

}

void vm_handler_LDXW(BPFInstruction_t instruction){

}

void vm_handler_LDXH(BPFInstruction_t instruction){

}

void vm_handler_LDXB(BPFInstruction_t instruction){

}

void vm_handler_LDXDW(BPFInstruction_t instruction){

}

void vm_handler_STW(BPFInstruction_t instruction){

}

void vm_handler_STH(BPFInstruction_t instruction){

}

void vm_handler_STB(BPFInstruction_t instruction){

}

void vm_handler_STDW(BPFInstruction_t instruction){

}

void vm_handler_STXW(BPFInstruction_t instruction){

}

void vm_handler_STXH(BPFInstruction_t instruction){

}

void vm_handler_STXB(BPFInstruction_t instruction){

}

void vm_handler_STXDW(BPFInstruction_t instruction){

}

void vm_handler_JA(BPFInstruction_t instruction){

}

void vm_handler_JEQ_IMM(BPFInstruction_t instruction){

}

void vm_handler_JEQ_REG(BPFInstruction_t instruction){

}

void vm_handler_JGT_IMM(BPFInstruction_t instruction){

}

void vm_handler_JGT_REG(BPFInstruction_t instruction){

}

void vm_handler_JGE_IMM(BPFInstruction_t instruction){

}

void vm_handler_JGE_REG(BPFInstruction_t instruction){

}

void vm_handler_JLT_IMM(BPFInstruction_t instruction){

}

void vm_handler_JLT_REG(BPFInstruction_t instruction){

}

void vm_handler_JLE_IMM(BPFInstruction_t instruction){

}

void vm_handler_JLE_REG(BPFInstruction_t instruction){

}

void vm_handler_JSET_IMM(BPFInstruction_t instruction){

}

void vm_handler_JSET_REG(BPFInstruction_t instruction){

}

void vm_handler_JNE_IMM(BPFInstruction_t instruction){

}

void vm_handler_JNE_REG(BPFInstruction_t instruction){

}

void vm_handler_JSGT_IMM(BPFInstruction_t instruction){

}

void vm_handler_JSGT_REG(BPFInstruction_t instruction){

}

void vm_handler_JSGE_IMM(BPFInstruction_t instruction){

}

void vm_handler_JSGE_REG(BPFInstruction_t instruction){

}

void vm_handler_JSLT_IMM(BPFInstruction_t instruction){

}

void vm_handler_JSLT_REG(BPFInstruction_t instruction){

}

void vm_handler_JSLE_IMM(BPFInstruction_t instruction){

}

void vm_handler_JSLE_REG(BPFInstruction_t instruction){

}

void vm_handler_CALL_IMM(BPFInstruction_t instruction){

}

void vm_handler_EXIT(BPFInstruction_t instruction){

}

void vm_print_instruction(BPFInstruction_t instruction){
    printf("{\n\topcode: %d\n",instruction.opcode);
    printf("\tdestRegister: %d\n",instruction.destRegister);
    printf("\tsourceRegister: %d\n",instruction.sourceRegister);
    printf("\toffset: %d\n",instruction.offset);
    printf("\timmediate: %d\n}\n",instruction.immediate);
}