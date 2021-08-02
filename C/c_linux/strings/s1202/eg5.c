#include<stdio.h>
main()
{
	char a[]={'v','e','c','t','o','r'};
	char b[]="vector";
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(b));
	b[2]=0;
	puts(b);
}
