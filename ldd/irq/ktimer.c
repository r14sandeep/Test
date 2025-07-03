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

/*
 * Kernel timer
 */

#define pr_fmt(fmt) "%s:%s: " fmt, KBUILD_MODNAME, __func__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

/*
 * Module parameter and data
 */

static int delay_ms = 1000;
module_param(delay_ms, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(delay_ms, "kernel timer delay is ms");

static struct ktimer_data {
	struct timer_list timer;
	long delay_jiffies;
	unsigned int data;
} ktinfo;

static void ktimer_handler(struct timer_list *t)
{
	struct ktimer_data *info = from_timer(info, t, timer);

	pr_info("kernel timer expired at %ld (data=%d)\n",
				jiffies, info->data++);

	/* Reschedule kernel timer */
	mod_timer(&info->timer, jiffies + info->delay_jiffies);
}

static int __init ktimer_init(void)
{
	/* Save kernel timer delay */
	ktinfo.delay_jiffies = msecs_to_jiffies(delay_ms);
	pr_info("delay is set to %dms (%ld jiffies)\n",
				delay_ms, ktinfo.delay_jiffies);

	/* Setup and start the kernel timer */
	timer_setup(&ktinfo.timer, ktimer_handler, 0);
	mod_timer(&ktinfo.timer, jiffies + ktinfo.delay_jiffies);

	pr_info("kernel timer module loaded\n");
	return 0;
}

static void __exit ktimer_exit(void)
{
	del_timer_sync(&ktinfo.timer);
	pr_info("kernel timer module unloaded\n");
}

module_init(ktimer_init);
module_exit(ktimer_exit);

MODULE_AUTHOR("Raghu Bharadwaj");
MODULE_DESCRIPTION("Kernel timer");
MODULE_LICENSE("Dual MIT/GPL");
