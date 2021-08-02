#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main()
{
	int ret;
	printf("process1:%d %d\n",getpid(),getppid());
	ret=vfork();
	if(ret==0)
	{
	//	printf("%d\n",ret);	
		printf("if\n");
	}
	else
	{
	//	printf("%d\n",ret);	
				
		printf("else\n");
		
	}	

	printf("process:%d %d\n",getpid(),getppid());
	
}
