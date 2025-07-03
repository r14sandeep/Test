obj-m =mod.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRs=$(PWD) modules

#clean:
#	rm -rf $(wildcard *.o *.ko *.mod.* .c* .t* test)
