#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/slab.h>

#define ATTACH_VM(symbol)  \
    static struct kprobe ##symbol_kp = {  \
        .symbol_name = #symbol  \
    };  \
    static int ##symbol_handler_pre(struct kprobe *p, struct pt_regs *regs){  \
        u64 program[] = {   \
         0x8500000000000001 \
        };  \
        attach_vm(regs,program,1);  \
        return 0;   \
    }   \
    static void ##symbol_handler_post(struct kprobe *p, struct pt_regs *regs, unsigned long flags){   \
    }   \
    static int ##symbol_handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr){    \
        printk(KERN_DEBUG "fault_handler: p->addr = 0x%p, trap #%dn", p->addr, trapnr); \
        return 0;   \
    }

#define REGISTER_KPROBE(symbol)  \
    int ret;    \
    ##symbol_kp.pre_handler = ##symbol_handler_pre; \
    ##symbol_kp.post_handler = ##symbol_handler_post;   \
    ##symbol_kp.fault_handler = ##symbol_handler_fault; \
    ret = register_kprobe(&##symbol_kp);    \
    if (ret < 0) {  \
        printk(KERN_DEBUG "register_kprobe failed, returned %d\n", ret);    \
        return ret; \
    }   \
    printk(KERN_DEBUG "Planted kprobe at %p\n", ##symbol_kp.addr);

#define UNREGISTER_KPROBE(symbol) \
    unregister_kprobe(&##symbol_kp);    \
    printk(KERN_DEBUG "kprobe at %p unregistered\n", ##symbol_kp.addr);





extern void init_inKernel_funcction_wrapper_map(void);
extern int attach_vm(struct pt_regs *regs, u64 program[], int size);

ATTACH_VM(sys_execve)

static int __init kprobe_init(void){
    init_inKernel_funcction_wrapper_map();
   
    REGISTER_KPROBE(sys_execve)
    return 0;
}

static void __exit kprobe_exit(void){
    UNREGISTER_KPROBE(sys_execve)
    // todo: free in kernel function wrapper map
}

module_init(kprobe_init)
module_exit(kprobe_exit)
MODULE_LICENSE("GPL");