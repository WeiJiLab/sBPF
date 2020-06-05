//
// Created by XingfengYang on 2020/6/2.
//

#ifndef NMCS_EBPF_VM_H
#define NMCS_EBPF_VM_H

#include "instruction.h"

typedef struct VM {
    u64 *memory;
    u32 memorySize;
    /**
     * r0 for vm return
     * r1-r6 for function return
     * r7-r9 for general useage
     * r10 for  stack pointer
     */
    u64 regs[10]; 
    BPFInstruction_t currentInstruction;
    u64 currentCode;
    u32 pc;
    u32 sp;
} VM_t;

/**
 * init the vm and it's memory space
 **/
void vm_init(VM_t &vm, u32 memorySize);


/**
 * verify code
 **/
bool vm_verify_code(VM_t &vm, u64 code);

/**
 * load program (u64 vector)
 **/
void vm_load_program(VM_t &vm, u64 *program);

/**
 * intsall program (elf file)
 **/
void vm_install_program(VM_t &vm, char *elfFile);

/**
 * fetch code from memory[pc]
 **/
u64 vm_fetch_code(VM_t &vm);

/**
 * decode the innstruction from u64 code
 **/
BPFInstruction_t vm_decode_code(VM_t &vm, u64 code);

/**
 * execute the current instruction
 **/
void vm_execute(VM_t &vm, BPFInstruction_t instruction);

/**
 * run the vm
 **/
void vm_run(VM_t &vm);

/**
 * print the instruction
 **/
void vm_print_instruction(VM_t &vm, BPFInstruction_t instruction);

#endif // NMCS_EBPF_VM_H
