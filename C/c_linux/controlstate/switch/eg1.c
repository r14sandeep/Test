#include<stdio.h>
main()
{
	int a,bit,i,j;
	char v;
	printf("enter data a,bit");
	scanf("%d%d",&a,&bit);
	printf("/******MENU*****/\nt:test bit\ns:set bit\nc:clear bit\n");
	printf("m:complement bit\nr:reverse bits\ni:i/p again\nq:quit");
loop:	printf("enter your choice");
	scanf(" %c",&v);
switch(v)
{
	case 't':
		printf("tested data %d\n",(a>>bit)&1);
		break;
	case 's':
		printf("set data %d\n",a|(1<<bit));
		break;
	case 'c':
		printf("clear data %d\n",a=a&~(1<<bit));
		break;
	case 'm':
		printf("complemoent of data%d\n",a^(1<<bit));
		break;
	case 'r':
		for(i=0;i<=31;i++)
		{	printf("%d",(a>>i)&1);
		}
		printf("\n");
		for(i=31,j=0;i>j;i--,j++)
		{
			if(((a>>i)&1)!=((a>>j)&1))
			{
				a^=(1<<i);
				a^=(1<<j);
			}
		}
		printf("%d\n",a);
		for(i=31;i<=0;i++)
		{	printf("%d",(a>>i)&1);
		}
		break;
	case 'i':
		printf("i/p again\n");
		goto loop;
		break;
	case 'q':
		break;
	default	:
		printf("invalid i/p\n");
}
}
