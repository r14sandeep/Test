#include<stdio.h>
main()
{
	float f;
	int *i,j;
	printf("enter f:");
	scanf("%f",&f);
	i=(int*)&f;
	for(j=31;j>=0;j--)
	{	
		printf("%d",(*i>>j)&1);

	}
//	char ch;
//	ch=*i;
//	printf("%d\n",ch);

}
