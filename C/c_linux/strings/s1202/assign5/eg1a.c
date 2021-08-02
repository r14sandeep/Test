///////copy string b in to a given position without using temp var
#include<stdio.h>
#include<string.h>
main()
{
	char a[20],b[20];
	int n,j,i;

	printf("enter a:");
	scanf("%s",a);
	printf("enter b:");
	scanf("%s",b);
	printf("a=%s\nb=%s\n",a,b);
	printf("%d\n",strlen(b));
	printf("enter position wher u need to insert s2:");
	scanf("%d",&j);
	n=strlen(b);
	memmove(a+n+j,a+j,strlen(a+j)+1);
	printf("%s\n",a);
	memmove(a+j,b,strlen(b));
	printf("%s\n",a);


}




