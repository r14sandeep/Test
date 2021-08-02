#include<stdio.h>
int findmax(int *p,int n)
{
	int a=-1,i,tempindex;
	for(i=0;i<n;i++)
	{
		if(p[i]>a)
		{	
			a=p[i];
			tempindex=i;
		}
	}
return tempindex;
}

main()
{
	int a[20],i,n;
	srand(getpid());
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		printf("%d,",a[i]);
	}
printf("\n");
printf("%d\n",findmax(a,n));
}

