#include<stdio.h>
main()
{
	unsigned int v=0x12345678,v1;
	unsigned char *p;
	unsigned short int *q;
	unsigned int *r;
	p=q=r=&v;
	v1=*p;
	printf("v=%x v1=%x\n",v,v1);
	v1=*q;
	printf("v=%x v1=%x\n",v,v1);
	v1=*r;
	printf("v=%x v1=%x\n",v,v1);
	printf("%lu %lu %lu\n",sizeof(p),sizeof(q),sizeof(r));


}
