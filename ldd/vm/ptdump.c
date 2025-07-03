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
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/page.h>
#include <asm/pgtable.h>
#include <linux/highmem.h>

#include <linux/device.h>

static unsigned int major;

int ptd_open(struct inode *i, struct file *filp)
{
	return 0;
}

int ptd_close(struct inode *i, struct file *filp)
{
	return 0;
}

ssize_t ptd_read(struct file *filp,char __user *buf, size_t count, loff_t *fpos)
{

	pgd_t *pgd;
	p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *ptep,pte;

	char *real;
	struct page *page=NULL;
	unsigned long t,addr=t=(unsigned long)buf;

	/* Access base address of PUD */
	pgd = pgd_offset(current->mm, addr);
	if (pgd_none(*pgd) || pgd_bad(*pgd))
        	goto out;

	pr_info("pgd.pgd %lu\n",(unsigned long)pgd->pgd);

	p4d = p4d_offset(pgd, addr);
   	 printk("p4d_val = 0x%lx\n", p4d_val(*p4d));
    	if (p4d_none(*p4d)) {
        	printk("not mapped in p4d\n");
        	return -1;
    	}

	/* access base address of PMD */
	pud = pud_offset(p4d,addr);
	if (pud_none(*pud) || pud_bad(*pud))
	        goto out;
	
	/* Find an entry in the second-level page table.. */
	pmd = pmd_offset(pud, addr);
	if (pmd_none(*pmd) || pmd_bad(*pmd))
	        goto out;

	pr_info("pud.pud %lu\n",(*pud).pud);

	ptep = pte_offset_map(pmd, addr);
	if (!ptep)
	        goto out;
	pte = *ptep;
	
	page = pte_page(pte);
	if (page)
        pr_info("Page frame struct is @ %p\n", page);

	real=kmap(page);

	t=t & 0x0fff;
	pr_info("offset: %x, gotaddr: %p\n",(unsigned)t,real+t);
	pr_info("%s:%s\n",__func__,real+t);
	
	/*
	 * Changing the value of the 1st char to 'B' and print here, and see that affect has
	   appeared in user-space or not by waiting on getchar()
	 */
	real[t]='B';
	pr_info("%s:%s\n",__func__,real+t);

	kunmap(page);
	pte_unmap(ptep);
out:
    return 0;
}

struct file_operations ptd_fops = {
	.owner		= THIS_MODULE,
	.open		= ptd_open,
	.release	= ptd_close,
	.read		= ptd_read,
};

struct class *cls;

int init_module(void)
{
	
	major = register_chrdev(0,"addtrans",&ptd_fops);
	if ( major <= 0 ) {
	   printk("Error in registering character device\n");
	   return -1;
	}
	
	printk("Assigned major number = %d\n",major);
	cls=class_create(THIS_MODULE,"test-page");
	pr_info("dev: %p\n",device_create(cls,NULL,MKDEV(major,0),NULL,"addtrans"));
	
	return 0;
}

void cleanup_module(void)
{
	device_destroy(cls,MKDEV(major,0));
	class_destroy(cls);
	unregister_chrdev(major,"addtrans");
	printk("Unloading\n");
}

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Raghu Bharadwaj <raghu@techveda.org>");

