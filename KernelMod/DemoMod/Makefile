obj-m += linux_kernel_netlink_mod_demo.o

linux_kernel_netlink_mod_demo.o: linux_kernel_netlink_mod_demo.c
	$(CC) -o $@ $<

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules


clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
