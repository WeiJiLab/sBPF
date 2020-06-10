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

};