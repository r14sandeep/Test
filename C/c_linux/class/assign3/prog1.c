//creat a MENU driven app which displys the following menu infinitely
/*t:test bit
  s:set bit
  c:clear bit*/
#include<stdio.h>
main()
{
	int a,bit,i,j;
	char v;
	printf("enter data and bit");
	scanf("%d%d",&a,&bit);
	printf("MENU\n t:test bit \n s:set bit\nc:clear bit\n");
	printf("m:complement bit\nr=reverse bits\ni=i/p again\nq:quit\n");
loop:	printf("enter the choice");
	scanf(" %c",&v);
if(v== 't')
	printf("tested data %d\n",(a>>bit)&1);
else if(v== 's')
	printf("set data %d\n",a|(1<<bit));
	else if(v== 'c')
		printf("clear data %d\n",a&~(1<<bit));	
	else if(v== 'm')
		printf("comp data %d\n",v^(1<<bit));
	else if(v== 'i')
		{ printf("i/p again\n");
		  goto loop;
		}
	else if(v== 'q')
		return;
	else if(v== 'r')
		{	for(i=0;i<=31;i++)
			{
				printf("%d",(a>>i)&1);
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
			printf("reversed data %d\n",a);
		}
	else {
		printf("invalid i/p\n");
		return;}
/*(v== 't')?printf("tested data %d\n",(a>>bit)&1):(v== 's')?printf("set data %d\n",a|(1<<bit)):(v== 'c')?printf("clear data %d\n",a&~(1<<bit)):(v== 'm')?printf("complemnt data  %d\n",a^(1<<bit)): 0;
*/


}
