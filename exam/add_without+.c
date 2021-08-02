#include<stdio.h>
int main()
{
	int num1,num2,res=0;
	printf("enter num1,num2:");
	scanf("%d%d",&num1,&num2);
	int index,i,j;
	for(index=0;index<8;index++)
	{
		i=(num1>>index)&1;
		j=(num2>>index)&1;
//		printf("%d:i=%d,j=%d\n",index,i,j);
		if(i&&j)
		{
	
			res|=(1<<(index+1));
//			printf("%d:i=%d,j=%d\n",index,i,j);
	//		for(i=7;i>=0;i--)
	//			printf("%d ",j=(res>>i)&&(1));
		}
		else if(i||j)
			{
				if((res>>index)&1)
				{	
					res|=(1<<(index+1));
					res&=~(1<<index);
				}
				else
					res|=(1<<index);
			}
	}
	printf("res=%d\n",res);			
}
