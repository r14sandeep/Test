#include<stdio.h>
main()
{
	double f=23.4,f1;
	int i=512,i1;
	char c='A',c1;
	void *p;
	p=&c;
	c1=*(char *)p;
	p=&i;
	i1=*(int *)p;
	p=&f;
	f1=*(double *)p;
	printf("%c %d %lf\n",c,i,f);
	printf("%c %d %lf\n",c1,i1,f1);

}
