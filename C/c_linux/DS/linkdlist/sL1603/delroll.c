#include"header.h"
void del(NODE **head)
{
	NODE *temp,*prev;
	int roll2del;
	if(*head==NULL)
	{
		printf("no data available\n");
		return;
	}
	printf("enter roll to be deleted:");
	scanf("%d",&roll2del);
	for(temp=*head;temp;temp->next)
	{
		if(temp->roll==roll2del)
			break;
		prev=temp;
	}
	if(temp==NULL)
	{
		printf("roll not found\n");return;

	}
	//////found at temp
	if(temp==(*head))
	{
		(*head)=(*head)->next;
	}
	else
		prev->next=temp->next;
	free(temp);
}
