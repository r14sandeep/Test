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
#include <linux/kernel.h>	/* pr_info() */
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/mm.h>

static void *buffer;
static int buf_size = 8192;

static int device_mmap(struct file *file, struct vm_area_struct *vma)
{
	int size;
	size = vma->vm_end - vma->vm_start;
	if (remap_pfn_range
	    (vma, vma->vm_start, virt_to_phys(buffer) >> PAGE_SHIFT, buf_size,
	     vma->vm_page_prot))
		return -EAGAIN;
	return 0;
}

static struct file_operations map_fops = {
	.owner = THIS_MODULE,
	.mmap = device_mmap,
};

static int map_count = 1;
static dev_t map_dev;

static struct cdev *map_cdev;

static int map_init(void)
{
	buffer = kzalloc(buf_size, GFP_USER);
	if (!buffer) {
		pr_err(KERN_INFO "kzalloc error.\n");
		return -1;
	}
	if (alloc_chrdev_region(&map_dev, 0, map_count, "mapdev")) {
		pr_err("alloc chrdev error.\n");
		return -1;
	}

	map_cdev = cdev_alloc();
	if (!map_cdev) {
		pr_err("cdev alloc error.\n");
		return -1;
	}
	map_cdev->ops = &map_fops;
	map_cdev->owner = THIS_MODULE;

	if (cdev_add(map_cdev, map_dev, map_count)) {
		pr_err("cdev add error.\n");
		return -1;
	}

	return 0;

}

static void map_cleanup(void)
{
	cdev_del(map_cdev);
	unregister_chrdev_region(map_dev,map_count);
	kfree(buffer);
}

module_init(map_init);
module_exit(map_cleanup);


MODULE_AUTHOR("Raghu Bharadwaj <raghu@techveda.org>");
MODULE_DESCRIPTION("mmap");
MODULE_LICENSE("Dual MIT/GPL");
