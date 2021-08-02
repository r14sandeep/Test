#include<stdio.h>
int main()
{
	int p[2],val=2;
	pipe(p);
	if(fork()==0)
	{
		val++;
		printf("in child=%d\n",val);
		write(p[1],&val,4);
		printf("child exiting\n");
	}
	else
	{
		val+=2;
		printf("in parent=%d\n",val);
		read(p[0],&val,4);
		val++;
		printf("pipe parent=%d\n",val);
		sleep(2);
		printf("parent exiting\n");
		
	
	}
	

}
