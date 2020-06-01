//
// Created by XingfengYang on 2020/5/29.
//

#include "../include/instruction.h"
#include <stdio.h>
#include <memory>

VM_t vm;
void vm_init(u32 memorySize){
    if(memorySize>65535){
        // exceed max memory, vm exited.
    }
    vm.memory = (u64*)malloc(memorySize*sizeof(u64));
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

void vm_print_instruction(BPFInstruction_t instruction){
    printf("{\n\topcode: %d\n",instruction.opcode);
    printf("\tdestRegister: %d\n",instruction.destRegister);
    printf("\tsourceRegister: %d\n",instruction.sourceRegister);
    printf("\toffset: %d\n",instruction.offset);
    printf("\timmediate: %d\n}\n",instruction.immediate);
}
