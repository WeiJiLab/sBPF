//
// Created by XingfengYang on 2020/5/13.
//

#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Neo Yang");
MODULE_DESCRIPTION("Just a test mod for NMCS");


static int __init demo_mod_init(void)
{
    printk(KERN_INFO "Hello, world 2\n");
    return 0;
}

static void __exit demo_mod_exit(void)
{
    printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(demo_mod_init);
module_exit(demo_mod_exit);
