obj-m += linux_kernel_mod_example.o

linux_kernel_mod_example.o:
	$(CC) -o linux_kernel_mod_example.o linux_kernel_mod_example.c

all:
	make -C /lib/modules/5.4.0-26-generic/build M=$(PWD) modules


clean:
	make -C /lib/modules/5.4.0-26-generic/build M=$(PWD) clean
