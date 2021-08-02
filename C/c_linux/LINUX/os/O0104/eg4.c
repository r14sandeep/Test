#include<stdio.h>
#include<stdlib.h>
void parentcode(void);
void childcode(void);
int pid[4];
main()
{
	pid[0]=getpid();
	if(pid[1]=fork())
	{
		if(pid[2]=fork())
		{
			if(pid[3]=fork())
				parentcode();
			else
				childcode();
		}
		else
			childcode();
	}
	else
		childcode();
}
void childcode(void)
{
	static int cnt=0;
	cnt++;
	printf("child %d\n",getpid());
	printf("%d %d %d %d\n",pid[0],pid[1],pid[2],pid[3]);
	exit(0);

}
void parentcode(void)
{
	printf("parent %d %d %d \n",pid[0],pid[1],pid[2],pid[3]);
	exit(0);

}
