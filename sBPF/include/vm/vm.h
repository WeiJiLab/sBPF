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
} VM;
typedef struct VM *VM_t;

VM_t vm_create(void);

void vm_init(VM_t vm, u32 memorySize);

_Bool vm_verify_code(VM_t vm, u64 code);

void vm_load_program(VM_t vm, u64 *program);

void vm_install_program(VM_t vm, char *elfFile);

u64 vm_fetch_code(VM_t vm);

BPFInstruction_t vm_decode_code(VM_t vm, u64 code);

void vm_execute(VM_t vm, BPFInstruction_t instruction);

void vm_run(VM_t vm);

void vm_print_instruction(VM_t vm, BPFInstruction_t instruction);

_Bool is_little_endion(void);

void setInKernelWrapper(void);

void setInstructionhandler(void);

#endif // NMCS_EBPF_VM_H
