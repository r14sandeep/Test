#include<stdio.h>
main()
{
	int ret;
	ret=fork();
	switch(ret)
	{
		case -1:perror("fork");exit(0);
		case 0:printf("child excllussive code\n");exit(0);
		deafult:printf("exclussive parent code\n");
			exit(0);
	}

}
