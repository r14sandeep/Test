//prog to print the binary value of given data:
#include<stdio.h>
main()
{
	int v,bit;
	printf("enter data:");
	scanf("%d",&v);
	bit=sizeof(int)*8-1;
loop: printf("%d",(v>>bit)&1);
	bit--;
	if(bit>=0)
		goto loop;


}
