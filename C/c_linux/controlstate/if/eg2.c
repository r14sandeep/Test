//test the bit value of given data:
#include<stdio.h>
main()
{
	int v,bit;
	printf("enter data:");
	scanf("%d",&v);
loop:	printf("enter bit to be tested:");
	scanf("%d",&bit);
	if(bit>sizeof(int)*8-1){
		printf("bit is incorrect,try again\n");
		goto loop;}
printf("%d\n",(v>>bit)&1);


}
