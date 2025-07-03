#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>

void init_func(void){
	printk("module insertedn");
	return;
}

void exit_func(void){
	printk("modele removedn");
	return;
}

module_init(init_func);
module_exit(exit_func);

MODULE_AUTHOR("SANDEEP");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_LICENSE("GPL");
