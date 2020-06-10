#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/slab.h>

#include "../../include/module/module.h"

extern void init_inKernel_funcction_wrapper_map(void);
extern int attach_vm(struct pt_regs *regs, u64 program[], int size);

// STEP 1: attach vm to kprobe symbol
ATTACH_VM(sys_execve)

static int __init sbpf_init(void){
    init_inKernel_funcction_wrapper_map();

    // STEP 2: register kprobe symbol
    REGISTER_KPROBE(sys_execve)
    return 0;
}

static void __exit sbpf_exit(void){
    // STEP 3: unregister kprobe symbol
    UNREGISTER_KPROBE(sys_execve)
    // todo: free in kernel function wrapper map
}

module_init(sbpf_init)
module_exit(sbpf_exit)
MODULE_AUTHOR("Neo Yang");
MODULE_LICENSE("GPL");