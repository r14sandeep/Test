#include"header.h"
void dellastnode(NODE **head)
{
	NODE *temp,*prev;
	temp=*head;
	if(*head==NULL)
	{
		printf("no data to del\n");
	}
	else
	{
	while(temp->next)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==*head)
	{
		free(temp);
		*head=NULL;
	}
	else
	{
		prev->next=0;
		free(temp);
	}
	}
}
