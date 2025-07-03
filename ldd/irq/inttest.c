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
#include <linux/interrupt.h>

#define SHARED_IRQ 1
static int irq = SHARED_IRQ, my_dev_id = 1, irq_counter = 0;
module_param(irq, int, S_IRUGO);

static irqreturn_t my_interrupt(int irq, void *dev_id)
{
	irq_counter++;
	dump_stack();
	pr_info("In the ISR: counter = %d\n", irq_counter);
	return IRQ_NONE;/* we return IRQ_NONE because we are just observing */
	/*return IRQ_HANDLED; */
}

static int __init my_init(void)
{
	if (request_irq
	    (irq, my_interrupt, IRQF_SHARED, "my_interrupt", 
             &my_dev_id))
		return -1;
	/* arg1: irq no
	   arg2: driver's interrupt handler
	   arg3: priority flag
	   arg4: name of the driver
	   arg5: unique identity for this handler 
	 */
	return 0;
}

static void __exit my_exit(void)
{
	/* verify if isr is running */
	synchronize_irq(irq);
	free_irq(irq, &my_dev_id);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Team veda");
MODULE_DESCRIPTION("Interrupt Handler Test");
MODULE_LICENSE("GPL");
