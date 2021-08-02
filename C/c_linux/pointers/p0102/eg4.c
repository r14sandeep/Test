#include<stdio.h>
main()
{
	float f=23.4;
	int *p=&f;
	int v,bit;
	printf("enter real data");
	scanf("%f",&f);
	v=*p;
	for(bit=31;bit>=0;bit--)
		printf("%d",(v>>bit)&1);
	


}
