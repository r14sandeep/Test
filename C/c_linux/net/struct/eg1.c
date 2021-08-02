#include<stdio.h>
main()
{
union u
{
	int i;
	char ch[2];
};
	union u a;
	a.ch[0]=3;
	a.ch[1]=2;
	printf("%d %d %d\n",a.ch[0],a.ch[1],a.i);
	

}
