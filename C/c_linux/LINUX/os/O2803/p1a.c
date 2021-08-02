#include<stdio.h>
main()
{
	printf("process %d %d\n",getpid(),getppid());
	sleep(3);
	system("ls");
	sleep(2);
	system("date");
	sleep(1);
	system("pwd");	
}
