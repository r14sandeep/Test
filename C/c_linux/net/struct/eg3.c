#include<stdio.h>
#include<stdlib.h>

main()
{
	struct node
	{
		int data;
		struct node *link;
	};
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	q=(struct node *)malloc(sizeof(struct node));
	printf("%d,%d\n",sizeof(p),sizeof(q));



}
