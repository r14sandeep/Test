#include<stdio.h>
main(int agrc,char **argv)
{
	int n1,n2;
	n1=atoi(argv[1]);
	n2=atoi(argv[3]);
	switch(argv[2][0])
	{
	case '+':printf("%d\n",n1+n2);break;


	}
}
