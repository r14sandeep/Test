#include<stdio.h>
int mystrncmp(char *a,char *b,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if((a[i]>b[i])||(a[i]<b[i]))
			return a[i]-b[i];
		//else if(a[i]<b[i])
		//	return a[i]-b[i];
	}
	return 0;

}
main()
{
	char a[10],b[10];
	int i;
	puts("enter a,b");
	gets(a);
	gets(b);
	//i=strncmp(a,b,2);
	i=mystrncmp(a,b,2);
	printf("%d\n",i);
}

