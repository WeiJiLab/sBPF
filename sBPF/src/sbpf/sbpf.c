#include "../../include/sbpf/sbpf.h"
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

void init_inKernel_funcction_wrapper_map(void){
    inKernelFuncWrapperMap = createHashMap(s32HashCode,s32Equal);
    wrapperFuncIterator = createHashMapIterator(inKernelFuncWrapperMap);
    setInKernelWrapper();
}

int attach_vm(struct pt_regs *regs, u64 program[], int size){
    VM_t vm = vm_create();
    vm_init(vm, size);
    vm_set_in_kernel_function_wrapper_map(vm, inKernelFuncWrapperMap);
    if(vm_verify_code(vm,program)){
        vm_load_program(vm,program);
        vm_run(vm);
    }
    vm_release(vm);
}