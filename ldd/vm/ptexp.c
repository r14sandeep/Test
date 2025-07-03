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
#include <linux/mm.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/highmem.h>
#include <linux/slab.h>

unsigned long vaddr = 0;

static unsigned long vaddr2paddr(unsigned long vaddr)
{
    pgd_t *pgd;
    p4d_t *p4d;
    pud_t *pud;
    pmd_t *pmd;
    pte_t *pte;
    char *kp;

    unsigned long offset = vaddr;
    struct page *page = NULL;

    pgd = pgd_offset(current->mm, vaddr);
    pr_info("pgd_val = 0x%lx\n", pgd_val(*pgd));
    pr_info("pgd_index = %lu\n", pgd_index(vaddr));
    if (pgd_none(*pgd)) {
        pr_err("not mapped in pgd\n");
        return -1;
    }

    p4d = p4d_offset(pgd, vaddr);
    pr_info("p4d_val = 0x%lx\n", p4d_val(*p4d));
    if (p4d_none(*p4d)) {
        pr_err("not mapped in p4d\n");
        return -1;
    }

    pud = pud_offset(p4d, vaddr);
    pr_info("pud_val = 0x%lx\n", pud_val(*pud));
    if (pud_none(*pud)) {
        pr_err("not mapped in pud\n");
        return -1;
    }

    pmd = pmd_offset(pud, vaddr);
    pr_info("pmd_val = 0x%lx\n", pmd_val(*pmd));
    pr_info("pmd_index = %lu\n", pmd_index(vaddr));
    if (pmd_none(*pmd)) {
        pr_err("not mapped in pmd\n");
        return -1;
    }

    pte = pte_offset_map(pmd, vaddr);
    pr_info("pte_val = 0x%lx\n", pte_val(*pte));
    pr_info("pte_index = %lu\n", pte_index(vaddr));
    if (pte_none(*pte)) {
        pr_err("not mapped in pte\n");
        return -1;
    }

    page = pte_page(*pte);
    if(page)
        pr_err("Page frame struct is @ %p\n", page);


     kp = page_address(page);
     offset = offset & 0x0fff;
     kp[offset]='T';
     pr_info("%s:%s\n",__func__,kp+offset);

     pte_unmap(pte);
     return 0;
}

static int __init v2p_init(void)
{

    unsigned long pgaddr = 0;

    pr_info("\n");

    vaddr = (unsigned long)kmalloc(1000 * sizeof(char),GFP_KERNEL);
    if (vaddr == 0) {
        pr_err("kmalloc failed..\n");
        return 0;
    }
    strcpy((char *)vaddr, "techveda:kmalloc allocatoin");
    pr_info("kmalloc_vaddr=0x%lx\n", vaddr);
    vaddr2paddr(vaddr);
  
    kfree((void *)vaddr);
    pr_info("\n\n");

    vaddr = 0;
    vaddr = (unsigned long)vmalloc(1000 * sizeof(char));
    if (vaddr == 0) {
        pr_err("vmalloc failed..\n");
        return 0;
    }
    strcpy((char *)vaddr, "techveda:vmalloc allocation");
    pr_info("vmalloc_vaddr=0x%lx\n", vaddr);
    vaddr2paddr(vaddr);
 
    pr_info("\n\n");

    pgaddr = __get_free_page(GFP_KERNEL);
    if (pgaddr == 0) {
        pr_err("__get_free_page failed..\n");
        return 0;
    }
    strcpy((char *)pgaddr, "techveda:page allocation");
    vaddr2paddr(pgaddr);

    vfree((void *)vaddr);
    free_page(pgaddr);
    
    return 0;
}

static void __exit v2p_exit(void)
{
    pr_info("vaddr to paddr module is leaving..\n");
}
module_init(v2p_init);
module_exit(v2p_exit);

MODULE_AUTHOR("Raghu Bharadwaj <raghu@techveda.org>");
MODULE_DESCRIPTION("address trans");
MODULE_LICENSE("Dual MIT/GPL");
