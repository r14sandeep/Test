# target: input files
# <tab> commands/scripts


obj-m  := usbprobe.o
obj-m   += usbdrv.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD)  modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf $(wildcard *.o *.ko *.mo* Mo* *.order)
	

