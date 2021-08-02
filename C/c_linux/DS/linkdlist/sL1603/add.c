#include"header.h"
void add(NODE **head)
{
	NODE *nu,*temp;
	temp=*head;
	nu=malloc(sizeof(NODE));
	printf("enter roll:");
	scanf("%d",&nu->roll);
	printf("enter name:");
	scanf("%s",&nu->name);
	printf("enter mark:");
	scanf("%f",&nu->mark);
	if(*head==NULL)
	{
		nu->next=NULL;
		*head=nu;
	}
	else
	{	
		while(temp->next)
			temp=temp->next;
		temp->next=nu;
		nu->next=NULL;

	}


}
