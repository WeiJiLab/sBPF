#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include "../../include/vm/vm.h"
#include <linux/slab.h>

HashMap_t inKernelFuncWrapperMap;
HashMapIterator_t wrapperFuncIterator;

int WRAPPER_print(VM_t vm){
    printk("Wrapper print invoked.\n");
    return 0;
}

void setInKernelWrapper(){
    int* key = (int*)kmalloc(sizeof(int), GFP_KERNEL);
    *key = 1;
    inKernelFuncWrapperMap->putFunc(inKernelFuncWrapperMap,(void*)key,(void*)&WRAPPER_print);
}

_Bool s32Equal(void *key1,void * key2){
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

static void init_inKernel_funcction_wrapper_map(void){
    inKernelFuncWrapperMap = createHashMap(s32HashCode,s32Equal);
    wrapperFuncIterator = createHashMapIterator(inKernelFuncWrapperMap);
    setInKernelWrapper();
}

static int attach_vm(struct pt_regs *regs,u64 program[], int size){
    VM_t vm = vm_create();
    vm_init(vm, size);
    vm_set_in_kernel_function_wrapper_map(vm, inKernelFuncWrapperMap);
    vm_load_program(vm,program);
    vm_run(vm);
    vm_release(vm);
}

static struct kprobe kp = {
    .symbol_name = "sys_execve"
};

static int handler_pre(struct kprobe *p, struct pt_regs *regs){
    u64 program[] = {
         0x8500000000000001
    };
    attach_vm(regs,program,1);
    return 0;
}
 
static void handler_post(struct kprobe *p, struct pt_regs *regs, unsigned long flags){

}

static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr){
    printk(KERN_DEBUG "fault_handler: p->addr = 0x%p, trap #%dn", p->addr, trapnr);
    return 0;
}

static int __init kprobe_init(void){
    init_inKernel_funcction_wrapper_map();
   
    int ret;
    kp.pre_handler = handler_pre;
    kp.post_handler = handler_post;
    kp.fault_handler = handler_fault;
 
    ret = register_kprobe(&kp);
    if (ret < 0) {
        printk(KERN_DEBUG "register_kprobe failed, returned %d\n", ret);
        return ret;
    }
    printk(KERN_DEBUG "Planted kprobe at %p\n", kp.addr);
    return 0;
}

static void __exit kprobe_exit(void){
    unregister_kprobe(&kp);
    printk(KERN_DEBUG "kprobe at %p unregistered\n", kp.addr);
}

module_init(kprobe_init)
module_exit(kprobe_exit)
MODULE_LICENSE("GPL");