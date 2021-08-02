#include<stdio.h>
scp 1.c 3.c 4.c 5.c rathoraj@192.168.2.117:~/raja
int main()
{
	int pos,index1,index2,cnt=0,prime;
	printf("enter which position prime number you want:");
	scanf("%d",&pos);
	for(index1=2;index1<=100;index1++)
	{
		for(index2=2;index2<=index1/2;index2++)
			if(index1%index2==0)
				break;
		if(index2>index1/2)
		{
			prime=index1;
			cnt++;
		}
		if(cnt==pos)
		{
			printf("prime number in positin %d is: %d\n",pos,prime);
			break;
		}
	
	}
}
