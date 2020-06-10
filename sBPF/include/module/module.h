//
// Created by XingfengYang on 2020/6/11.
//
#ifndef NMCS_EBPF_MODULE_H
#define NMCS_EBPF_MODULE_H

#define ATTACH_VM(symbol)  \
    static struct kprobe symbol##_kp = {  \
        .symbol_name = #symbol  \
    };  \
    static int symbol##_handler_pre(struct kprobe *p, struct pt_regs *regs){  \
        u64 program[] = {   \
         0x8500000000000001 \
        };  \
        attach_vm(regs,program,1);  \
        return 0;   \
    }   \
    static void symbol##_handler_post(struct kprobe *p, struct pt_regs *regs, unsigned long flags){   \
    }   \
    static int symbol##_handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr){    \
        printk(KERN_DEBUG "fault_handler: p->addr = 0x%p, trap #%dn", p->addr, trapnr); \
        return 0;   \
    }

#define REGISTER_KPROBE(symbol)  \
    symbol##_kp.pre_handler = symbol##_handler_pre; \
    symbol##_kp.post_handler = symbol##_handler_post;   \
    symbol##_kp.fault_handler = symbol##_handler_fault; \
    int ret = register_kprobe(&symbol##_kp);    \
    if (ret < 0) {  \
        printk(KERN_DEBUG "register_kprobe failed, returned %d\n", ret);    \
        return ret; \
    }   \
    printk(KERN_DEBUG "Planted kprobe at %p\n", symbol##_kp.addr);

#define UNREGISTER_KPROBE(symbol) \
    unregister_kprobe(&symbol##_kp);    \
    printk(KERN_DEBUG "kprobe at %p unregistered\n", symbol##_kp.addr);


#endif // NMCS_EBPF_MODULE_H