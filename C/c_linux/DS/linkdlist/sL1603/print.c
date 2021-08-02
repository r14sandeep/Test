#include"header.h"
void print(NODE *head)
{
	while(head)
	{
		printf("%d %s %0.2f\n",head->roll,head->name,head->mark);
		head=head->next;
	}

}
