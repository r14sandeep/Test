#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_LICENSE("Dual BSD/GPL");
void fun(int a)
{
	int s=a*2;
	printk("s=%d\n",s);

}
static int hello_init(void)
{
	printk("<1>:Hello world\n");
	fun(10);
	return 0;
} 
static void hello_exit(void)
{
	printk("bie\n");
}

module_init(hello_init);
module_exit(hello_exit);
