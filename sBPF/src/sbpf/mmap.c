#include "../../include/sbpf/mmap.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/init.h> 
#include <linux/fs.h> 
#include <linux/mm.h> 
#include <asm/uaccess.h>

#define MAX_SIZE (PAGE_SIZE * 2)   /* max size mmaped to userspace */

static struct file_operations fops = {
    .open       = kprobe_open,
    .read       = kprobe_read,
    .write      = kprobe_write,
    .llseek     = kprobe_lseek,
    .mmap       = kprobe_mmap,
    .release    = kprobe_release,
};

static int kprobe_open(struct inode *inodep, struct file *filep){
    printk(KERN_INFO "MWR: Device has been opened\n");
    filep->private_data = kzalloc(size, GFP_KERNEL);
    if (filep->private_data == NULL){
        return -1;
    }
    return 0;
}

static int kprobe_mmap(struct file *filp, struct vm_area_struct *vma){
    printk(KERN_INFO "MWR: Device mmap\n");
    if(remap_pfn_range(vma, vma->vm_start, virt_to_pfn(filp->private_data), vma->vm_end - vma->vm_start, vma->vm_page_prot)){
        printk(KERN_INFO "MWR: Device mmap failed\n");
        return -EAGAIN;
    }
    printk(KERN_INFO "MWR: Device mmap OK\n");
    return 0;
}


int init_kprobe_mmap(void){
    if(!proc_create("kprobe",0600,NULL,&fops)){
        return -1;
    }
    return 0;
}