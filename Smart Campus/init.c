#include<stdio.h>
#include<linux/init.h>
#include<linux/module.h>
int main()
{
	int n=1;
	while(n)
	{
		printf("%d\n",n);
		printk("%d\n",n);
		n++;
		sleep(1);
		if(n==100000)
		{puts("break");break;}
	}
}
