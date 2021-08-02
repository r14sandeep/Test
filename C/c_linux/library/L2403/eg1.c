#include<stdio.h>
#include<dlfcn.h>
#include<sys/resource.h>
int sum(int,int);
int mul(int,int);
main()
{
	int r,v1,v2,ch;
	void *handle;
	int (*p)(int,int);
	puts("enter v1,v2");
	scanf("%d%d",&v1,&v2);
	printf("enter 1:sum 2:mul\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		handle=dlopen("lib/libD.so",RTLD_LAZY);
		p=dlsym(handle,"sum");
		r=(*p)(v1,v2);
		printf("sum=%d\n",r);
		dlclose(handle);
	}
	else if(ch==2)
	{
		//handle=dlopen("lib/libD.so",RTLD_LAZY);
		handle=dlopen("lib/libD.so",RTLD_LAZY);
		p=dlsym(handle,"mul");
		r=(*p)(v1,v2);
		printf("mul=%d\n",r);
		dlclose(handle);
		

	}

}
