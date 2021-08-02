/*manage the i/p not to get repeated*/


#include<stdio.h>
main()
{
	int a[20],i,j,n;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		printf("enter data:");
loop:		scanf("%d",&a[i]);
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{	printf("repeated data,so enter diff data\n");
				goto loop;
			}
		}	
		printf("a[%d]=%c\n",i,a[i]);
		

	}





}
