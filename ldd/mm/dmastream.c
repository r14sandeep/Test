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
#include <linux/pci.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/dmapool.h>

int direction = DMA_TO_DEVICE;

static void *kbuf;
static dma_addr_t handle;
static struct device *dev;
static int size = 512;

static int dma_init (void)
{

     dev = kzalloc(sizeof(struct device), GFP_KERNEL);
     dev_set_name(dev, "dmatest");
     device_register(dev);

     kbuf = kmalloc (size, GFP_KERNEL | GFP_DMA);
    if (kbuf == NULL){
	    pr_err("allocation failed\n");
    	    return -ENOMEM;
    }

    handle = dma_map_single (dev, kbuf, size, direction);
     if (dma_mapping_error(dev, handle)) {
                pr_err("dma mapping failed\n");
                return -EINVAL;
        }

    pr_info("kbuf=%12p, handle=%12p, size = %d\n", kbuf,
                (unsigned long *)handle, (int)size);

     strcpy((char *)kbuf, "mapped buffer");
     pr_info("DATA: %s\n", (char *)kbuf);

    dma_unmap_single (NULL, handle, size, direction);
    kfree (kbuf);

    return 0;
}
static void dma_exit (void)
{
	 dma_unmap_single (dev, handle, size, direction);
    	 kfree (kbuf);
	 device_unregister(dev);
}

module_init (dma_init);
module_exit (dma_exit);

MODULE_AUTHOR ("Raghu Bharadwaj <raghu@techveda.org>");
MODULE_DESCRIPTION ("DMA interface test");
MODULE_LICENSE ("Dual MIT/GPL");
