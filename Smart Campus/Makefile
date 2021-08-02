obj-m:=init.o
KDIR:=/lib/module/'uname -a'/build
PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)
