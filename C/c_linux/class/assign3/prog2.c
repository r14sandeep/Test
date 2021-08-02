#include<stdio.h>
main()
{
	char ch;
	int data,bit,i,j;
	printf("enter data:");
	scanf("%d",&data);
	for(i=31;i>=0;i--)
		printf("%d",(data>>i)&1);
	printf("bits are from 0 to %d\n",sizeof(int)*8-1);
	printf("t-test bit\ns-set bit\nc-clearbit\nm-complimentbit\nr-reversebitq-quit\n");
	printf("enter choice:\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 't':
			printf("enter bit to be testd:");
			scanf("%d",&bit);
			printf("bit is%d\n",(data>>bit)&1);break;
		case 's':
			printf("enter bit to be testd:");
			scanf("%d",&bit);
			data|=(1<<bit);
			printf("data aftr set %d\n",data);break;
		case 'c':printf("enter bit to comptd:");
			scanf("%d",&bit);
			data&=~(1<<bit);
			printf("data after cleard %d\n",data);break;
		case 'm':
			printf("enter bit to be testd:");
			scanf("%d",&bit);
			data^=(1<<bit);printf("comp data %d\n",data);break;
			printf("enter bit to be testd:");
		case 'r':for(i=31,j=0;i>j;i--,j++)
			{
				if(((data>>i)&1)!=((data>>j)&1))
				{
					data^=(1<<i);
					data^=(1<<j);
				}
			}
			for(i=31;i>=0;i--)
			{
				printf("%d",(data>>i)&1);
			}
			break;

		default:printf("invallid data\n");break;
		

	}


}
