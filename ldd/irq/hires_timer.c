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
 * High resolution timer
 */

#define pr_fmt(fmt) "%s:%s: " fmt, KBUILD_MODNAME, __func__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>

/*
 * Module parameter and data
 */

static int delay_ns = 1000000000;
module_param(delay_ns, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(delay_ns, "kernel timer delay is ns");

static struct hires_timer_data {
	struct hrtimer timer;
	unsigned int data;
} hires_tinfo;

static enum hrtimer_restart hires_timer_handler(struct hrtimer *ptr)
{
	struct hires_timer_data *info = container_of(ptr,
					struct hires_timer_data, timer);

	pr_info("kernel timer expired at %ld (data=%d)\n",
				jiffies, info->data++);

	/* Now forward the expiration time and ask to be rescheduled */
	hrtimer_forward_now(&info->timer, ns_to_ktime(delay_ns));
	return HRTIMER_RESTART;
}


static int __init hires_timer_init(void)
{
	/* Set up hires timer delay */

	pr_info("delay is set to %dns\n", delay_ns);

	/* Setup and start the hires timer */
	hrtimer_init(&hires_tinfo.timer, CLOCK_MONOTONIC,
				HRTIMER_MODE_REL | HRTIMER_MODE_SOFT);
	hires_tinfo.timer.function = hires_timer_handler;
	hrtimer_start(&hires_tinfo.timer, ns_to_ktime(delay_ns),
				HRTIMER_MODE_REL | HRTIMER_MODE_SOFT);

	pr_info("hires timer module loaded\n");
	return 0;
}

static void __exit hires_timer_exit(void)
{
	hrtimer_cancel(&hires_tinfo.timer);

	pr_info("hires timer module unloaded\n");
}

module_init(hires_timer_init);
module_exit(hires_timer_exit);

MODULE_AUTHOR("Raghu Bharadwaj <raghu@techveda.org>");
MODULE_DESCRIPTION("HR timer");
MODULE_LICENSE("Dual MIT/GPL");
