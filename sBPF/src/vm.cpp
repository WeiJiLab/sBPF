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
    u8  opCode         = (code >> 56) & 0xFF;
    u8  destRegister   = (code >> 52) & 0xF;
    u8  sourceRegister = (code >> 48) & 0xF;
    s16 offset         = (code >> 32) & 0xFFFF;
    s32 immediate      = code & 0xFFFFFFFF;

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
