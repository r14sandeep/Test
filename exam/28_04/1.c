#include<stdio.h>
//wap replace bit in int x from bit pos a to b from another int y

int main()
{
	int val1,val2,bit1,bit2;
	int index,status1,status2;
	printf("enter val1,val2:");
	scanf("%d%d",&val1,&val2);
	printf("enter the bits to changed from a to b:");
	scanf("%d%d",&bit1,&bit2);
	if((bit1>bit2)||(bit1<0)||(bit2<0))
	{
		printf("invalid bits\n");
		return;
	}
	printf("before replace\n");
	printf("val1:");
	for(index=7;index>=0;index--)
		printf("%d",(val1>>index)&1);
	printf("\nval2:");
	for(index=7;index>=0;index--)
		printf("%d",(val2>>index)&1);
	while(bit1<=bit2)
	{
		status1=(val1>>bit1)&1;
		status2=(val2>>bit1)&1;
		if(status1!=status2)
			val1^=(1<<bit1);
		bit1++;
	}
	printf("after repace\n");
	printf("val1:");
	for(index=7;index>=0;index--)
		printf("%d",(val1>>index)&1);
	printf("\nval2:");
	for(index=7;index>=0;index--)
		printf("%d",(val2>>index)&1);
	
}
