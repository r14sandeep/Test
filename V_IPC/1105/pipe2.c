#include"header.h"
int main()
{
	int p[2],arr[5]={-1,2,5,1,-4};
	int val,sum;
	pipe(p);
	val=fork();
	if(val)
	{
		puts("parent writing");
		write(p[1],&arr,sizeof(arr));
		waitpid(val);
		read(p[0],&sum,4);
		printf("sum:%d\n",sum);
		puts("parent exiting");
	}
	else
	{
		int ch_arr[5],pid,index,temp[5],i=0;
		read(p[0],&ch_arr,20);
		for(index=0;index<5;index++)
			if(arr[index]>0)
				temp[i++]=arr[index];
		puts("child1 writing");
		pid=fork();
		if(pid==0)
		{
			int a[5],sum=0,in;
			read(p[0],&a,20);
			for(in=0;in<5;in++)
				sum+=a[in];
			puts("child2 writing");
			write(p[1],&sum,4);
			puts("child2 exiting");
			exit(0);
		}
		else
		{
			write(p[1],&temp,i*4);

		}
		waitpid(pid);
		puts("child1 exiting");
		exit(0);
	}

}
