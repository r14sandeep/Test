/*
 * ******************************************************************************
 * This program is part of the source code provided with "Linux Device Drivers"
 * Course offered by Techveda <www.techveda.org>
 *
 * (C) 2020 Raghu Bharadwaj/Techveda
 *
 * Git repository:
 *   https://gitlab.com/techveda/ldd
 * ******************************************************************************
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <asm/io.h>

#define IOAPIC_BASE 0xFEC00000

#define CHAR_DEV_NAME "capic"
#define MAJORNO 190
#define MINORNO 0


struct apic_status {
	int tpins;
	unsigned long pins_status[23];
};


struct drv_private {
	dev_t mydev;
	struct cdev *apic_cdev;
	struct file_operations apic_operations;
	int ioredtlb[50];
	int count;
};

struct drv_private info = {
	.count = 1
};

int ioredtlb[] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
                0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
                0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21,
                0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
                0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,
                0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33,
                0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F
};

int apic_open (struct inode *inode, struct file *file)
{
	pr_info("%s: Invoked", __func__);
	return 0;
}

int apic_release (struct inode * inode, struct file *file)
{
	pr_info("%s: Invoked", __func__);
	return 0;
}

ssize_t apic_read_status (struct file *file, char __user *buf, size_t lbuf, loff_t *offset) 
{	
        int i, j;
        unsigned long val_lo, val_hi;
        void *ioregsel, *iowin, *io;

	struct apic_status apic_st;

       	pr_info("%s: Invoked", __func__);

	/* buf size should not be less than 1 */
	if(lbuf < sizeof(struct apic_status))
		return -EINVAL;

        io = ioremap(IOAPIC_BASE, PAGE_SIZE);

        ioregsel = (void *)((long)io + 0x00);
        iowin = (void *)((long)io + 0x10);
	
	apic_st.tpins = 23;
	
        for (i = 0, j = 0; i < apic_st.tpins; i++, j++) {
		apic_st.pins_status[0] = 0;

                iowrite32(ioredtlb[j], ioregsel);
                val_lo = ioread32(iowin);

                j++;
                iowrite32(ioredtlb[j], ioregsel);
                val_hi = ioread32(iowin);
		
		apic_st.pins_status[i] = (val_hi << 32) | val_lo;

		pr_info("--> %ld", apic_st.pins_status[i]);

                if ((i % 3) == 0)
                        printk("\n");
                //printk("  0x%02X : ", i);
                //printk("%08X%08X  ", val_hi, val_lo);
        }

	copy_to_user(buf, &apic_st, sizeof(apic_st));

	return 1;
}

struct file_operations apic_fops = {
	.open = apic_open,
	.release = apic_release,
	.read = apic_read_status,
};

static int  apic_init(void)
{
	int ret;
        info.mydev = MKDEV(MAJORNO, MINORNO);

        register_chrdev_region(info.mydev, info.count, CHAR_DEV_NAME);

        /* Allocate cdev instance */
        info.apic_cdev = cdev_alloc();

        /* Initialize cdev with fops object */
        cdev_init(info.apic_cdev, &apic_fops);

        /* Register cdev with vfs(devtmpfs) */
        ret = cdev_add(info.apic_cdev, info.mydev, info.count);
        if(ret < 0) {
                pr_err("Error registering device driver");
                return ret;
        }

	pr_info("%s: Module loaded", __func__);

        return 0;
	
}

static void apic_exit(void)
{
	/* Remove cdev */
        cdev_del(info.apic_cdev);

        /* Free major/minor no's used */
        unregister_chrdev_region(info.mydev, info.count);


	pr_info("%s: Module unloaded", __func__);
}


module_init(apic_init);
module_exit(apic_exit);

MODULE_AUTHOR("undefined");
MODULE_DESCRIPTION("RTC : Driver interfaced through VFS");
MODULE_LICENSE("GPL");
