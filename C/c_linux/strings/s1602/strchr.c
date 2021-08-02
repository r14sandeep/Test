#include<stdio.h>
#include<string.h>
main()
{
	char a[100],ch,*p;
	puts("enter a string:");
	gets(a);
	printf("enter char:");
	scanf("%c",&ch);
	printf("%u\n",&a[0]);
	//p=strchrnul(a,ch);
	p=strchr(a,ch);
	//printf("%d\n",&a[0]);
	printf("%u\n",p);
//	printf("%d\n",strchr(a,ch));

}
