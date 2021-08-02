#include<stdio.h>
main()
{
	printf("process %d %d\n",getpid(),getppid());
	//sleep(3);
	system("./p2&");
	//sleep(2);
	system("./p2&");
	//sleep(1);
	system("./p2&");	
	
}
