//prog to print the no.of digits of given no:
#include<stdio.h>
main()
{
	int v,count=0;
	printf("enter an int");
	scanf("%d",&v);
loop:	count++;
	v=v/10;
	if(v)
	   goto loop;
	printf("%d\n",count);

}
