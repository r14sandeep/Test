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
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/delay.h>

static void t_fun(unsigned long t_arg);

static struct simp {
	int i;
	int j;
} t_data;

static DECLARE_TASKLET(t_name, t_fun, (unsigned long)&t_data);

static int __init my_init(void)
{
	t_data.i = 100;
	t_data.j = 200;
	pr_info(" scheduling my tasklet, jiffies= %ld \n", jiffies);
	tasklet_schedule(&t_name);
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("\nHello: cleanup_module loaded at address 0x%p\n",
		cleanup_module);
}

static void t_fun(unsigned long t_arg)
{
	struct simp *datum;
	datum = (struct simp *)t_arg;
	pr_info("Entering t_fun, datum->i = %d, jiffies = %ld\n",
		datum->i, jiffies);
	pr_info("Entering t_fun, ,in context of %s with pid = %d\n",
		current->comm, current->pid);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("support@techveda.org");
MODULE_LICENSE("GPL");
