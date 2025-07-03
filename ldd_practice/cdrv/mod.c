#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/init.h>

void func(){
	printk("%s\n",__func__);
}
int init(){

	printk("%s inserted\n",__func__);
	return 0;
}
void cleanup(){
	printk("%s removed\n",__func__);
}

module_init(func);
module_exit(cleanup);
