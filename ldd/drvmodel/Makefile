# Makefile

# Makefile template for Linux LKMs (Loadable Kernel Modules); besides
# the 'usual' targets (the build, install and clean), we incorporate targets to
# do useful (and indeed required) stuff like:
#  - adhering to kernel coding style (indent+checkpatch)
#  - several static analysis targets (via sparse, gcc, flawfinder, cppcheck)
#  - two 'dummy' dynamic analysis targets (KASAN, LOCKDEP)
#  - a packaging (.tar.xz) target and
#  - a help target.

# To support cross-compiling for kernel modules:
# For architecture (cpu) 'arch', invoke make as:
#  make ARCH=<arch> CROSS_COMPILE=<cross-compiler-prefix> 
ifeq ($(ARCH),arm)
  # *UPDATE* 'KDIR' below to point to the ARM Linux kernel source tree on your box
  KDIR ?= ~/bbb_work/kernel_bbb
else ifeq ($(ARCH),arm64)
  # *UPDATE* 'KDIR' below to point to the ARM64 (Aarch64) Linux kernel source
  # tree on your box
  KDIR ?= ~/kernel/linux-5.4.45
else ifeq ($(ARCH),powerpc)
  # *UPDATE* 'KDIR' below to point to the PPC64 Linux kernel source tree on your box
  KDIR ?= ~/kernel/linux-5.4.45
else
  # 'KDIR' is the Linux 'kernel headers' package on your host system; this is
  # usually an x86_64, but could be anything.
  KDIR ?= /lib/modules/$(shell uname -r)/build
endif

obj-m          += drv_generic_skel.o
EXTRA_CFLAGS   += -DDEBUG

all:
	@echo
	@echo '-- Building : KDIR=${KDIR} ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} EXTRA_CFLAGS=${EXTRA_CFLAGS} --'
	@echo
	make -C $(KDIR) M=$(PWD) modules
install:
	@echo
	@echo "-- installing --"
	@echo
# seems to work when we use M=$(shell pwd)
	make -C $(KDIR) M=$(shell pwd) modules_install
	#make -C $(KDIR) M=$(PWD) modules_install
clean:
	@echo
	@echo "-- cleaning --"
	@echo
	make -C $(KDIR) M=$(PWD) clean
	rm -f *~ *.o.ur-safe

#--------------- More (useful) targets! -------------------------------
INDENT := indent

# code-style : "wrapper" target over the following kernel code style targets
code-style:
	make indent
	make checkpatch

# indent- "beautifies" C code - to conform to the the Linux kernel
# coding style guidelines.
# Note! original source file(s) is overwritten, so we back it up.
indent:
	@echo
	@echo "-- applying kernel code style indentation with indent --"
	@echo
	mkdir bkp 2> /dev/null; cp -f *.[chsS] bkp/
	${INDENT} -linux *.[chsS]
	  # add source files as required

# Detailed check on the source code styling / etc
checkpatch:
	make clean
	@echo
	@echo "-- kernel code style check with checkpatch.pl --"
	@echo
	$(KDIR)/scripts/checkpatch.pl --no-tree -f *.c
	  # add source files as required

#--- Static Analysis
# sa : "wrapper" target over the following kernel static analyzer targets
sa:
	make sa_sparse
	make sa_gcc
	make sa_flawfinder
	make sa_cppcheck

# static analysis with sparse
sa_sparse:
	make clean
	@echo
	@echo "-- static analysis with sparse --"
	@echo
	make C=2 -C $(KDIR) M=$(PWD) modules

# static analysis with gcc
sa_gcc:
	make clean
	@echo
	@echo "-- static analysis with gcc --"
	@echo
	make W=1 -C $(KDIR) M=$(PWD) modules

# static analysis with flawfinder
sa_flawfinder:
	make clean
	@echo
	@echo "-- static analysis with flawfinder --"
	@echo
	flawfinder *.c

# static analysis with cppcheck
sa_cppcheck:
	make clean
	@echo
	@echo "-- static analysis with cppcheck --"
	@echo
	cppcheck --language=c -q --force .

# Packaging; just tar.xz as of now
PKG_NAME := drv_generic
tarxz-pkg:
	rm -f ../${PKG_NAME}.tar.xz 2>/dev/null
	make clean
	@echo
	@echo "-- packaging --"
	@echo
	tar caf ../${PKG_NAME}.tar.xz *
	ls -l ../${PKG_NAME}.tar.xz
	@echo '== package created: ../$(PKG_NAME).tar.xz =='

help:
	@echo '=== Makefile Help : additional targets available ==='
	@echo
	@echo 'TIP: type make <tab><tab> to show all valid targets'
	@echo

	@echo '-- 'usual' kernel LKM targets --'
	@echo 'typing "make" or "all" target : builds the kernel module object (the .ko)'
	@echo 'install     : installs the kernel module(s) to INSTALL_MOD_PATH (defaults: /lib/modules/$(uname -r)/'
	@echo 'clean       : cleanup - remove all kernel objects, temp files/dirs, etc'

	@echo
	@echo '-- kernel code style targets --'
	@echo 'code-style : "wrapper" target over the following kernel code style targets'
	@echo ' indent     : run the $(INDENT) utility on source file(s) to indent them as per the kernel code style'
	@echo ' checkpatch : run the kernel code style checker tool on source file(s)'

	@echo
	@echo '-- kernel static analyzer targets --'
	@echo 'sa         : "wrapper" target over the following kernel static analyzer targets'
	@echo ' sa_sparse  : run the static analysis sparse tool on the source file(s)'
	@echo ' sa_gcc     : run gcc with option -W1 ("Generally useful warnings") on the source file(s)'
	@echo ' sa_flawfinder : run the static analysis flawfinder tool on the source file(s)'
	@echo 'TIP: use coccinelle as well (requires spatch): https://www.kernel.org/doc/html/v4.15/dev-tools/coccinelle.html'

	@echo
	@echo '-- kernel dynamic analysis targets --'
	@echo 'da_kasan   : DUMMY target: this is to remind you to run your code with the dynamic analysis KASAN tool enabled; requires configuring the kernel with CONFIG_KASAN On, rebuild and boot it'
	@echo 'da_lockdep : DUMMY target: this is to remind you to run your code with the dynamic analysis LOCKDEP tool (for deep locking issues analysis) enabled; requires configuring the kernel with CONFIG_PROVE_LOCKING On, rebuild and boot it'
	@echo 'TIP: best to build a debug kernel with several kernel debug config options turned On, boot via it and run all your test cases'

	@echo
	@echo '-- misc targets --'
	@echo 'tarxz-pkg  : tar and compress the LKM source files as a tar.xz into the dir above; allows one to transfer and build the module on another system'
	@echo 'help       : this help target'
