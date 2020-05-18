obj-m += linux_kernel_netlink_mod_demo.o

linux_kernel_netlink_mod_demo.o: linux_kernel_netlink_mod_demo.c
	$(CC) -o $@ $<

all:
	make -C /lib/modules/5.4.0-26-generic/build M=$(PWD) modules


clean:
	make -C /lib/modules/5.4.0-26-generic/build M=$(PWD) clean
