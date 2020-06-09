obj-m += sBPF.o

sBPF-y += src/module/module.o
sBPF-y += src/vm/hashmap.o
sBPF-y += src/vm/vm.o

KDIR := /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules 

clean:
	find ./ -regextype posix-extended -regex ".*\.(ko|o|mod.c|order|symvers|d|cmd|mod)" | xargs rm -f
