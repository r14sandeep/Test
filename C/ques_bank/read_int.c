#include<stdio.h>
int main()
{
	int i=296;
	char *p=(char*)&i;
	printf("%u\n",sizeof(p));
	printf("%d\n",*p);
	p++;
	printf("%d\n",*p);
	p++;
	printf("%d\n",*p);
	p++;
	printf("%d\n",*p);
	p++;

}
