#include"header.h"
//int main(int argc,char **argv)
int main(int argc,char **argv)
{
	int sum=0,v1,v2;
//	sum=atoi(argv[1])+atoi(argv[2]);
//	scanf("%d%d",&v1,&v2);
//	sum=v1+v2;
	for(v1=1;v1<argc;v1++)
		sum+=atoi(argv[v1]);
	printf("sum:%d\n",sum);

}
