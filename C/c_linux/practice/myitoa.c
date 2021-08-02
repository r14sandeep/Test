#include<stdio.h>
char* myitoa(int n)
{
	char a[10];
	int i,j,k,t;
	
	for(i=0;i<10;i++)
	{	
		t=n%10;
		a[i]=t+48;
		n=n/10;
		if(n==0)
		{
			a[i+1]='\0';
			break;
		}
	}
	k=strlen(a);
	for(i=0,j=k-1;i<j;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	puts(a);
	return a;
}
main()
{
	int n;	
	char *p=NULL;
	printf("enter n:");
	scanf("%d",&n);
	p=myitoa(n);
	puts(p);
	//printf("%s\n",p);
}
