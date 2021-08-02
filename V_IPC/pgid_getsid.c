#include<stdio.h>
int main()
{
	printf("gid:%d,sid:%d\n",getpgid(),getsid());
	if(fork()==0)
	printf("gid:%d,sid:%d\n",getpgid(),getsid());
	else
	printf("gid:%d,sid:%d\n",getpgid(),getsid());
	
}
