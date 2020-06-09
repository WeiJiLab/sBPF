obj-m += sBPF.o

sBPF-y += src/module.o

KDIR := /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules 

clean:
	find ./ -regextype posix-extended -regex ".*\.(ko|o|mod.c|order|symvers|d|cmd|mod)" | xargs rm -f
