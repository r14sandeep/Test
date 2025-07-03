# target & input files
obj-m := btint.o
obj-m += bt_thrint.o

#variable/macro to hold kernel-headers/kernel-sourse directory path
//KDIR = /lib/modules/$(shell uname -r)/build

KDIR = /home/raghu/linux-5.4.34

#command to convert input files into described target
#this command uses kbuild scripts of kernel-header/source folder specified

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
