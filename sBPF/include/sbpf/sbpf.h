//
// Created by XingfengYang on 2020/6/10.
//
#include "../vm/vm.h"

#ifndef NMCS_EBPF_H
#define NMCS_EBPF_H

int WRAPPER_print(VM_t vm);

void setInKernelWrapper(void);

_Bool s32Equal(void *key1,void * key2);

int s32HashCode(HashMap_t hashMap, void *key);

void init_inKernel_funcction_wrapper_map(void);

int attach_vm(struct pt_regs *regs, u64 program[], int size);

#endif // NMCS_EBPF_H