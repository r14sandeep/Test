#include"myheader.h"
void input(struct dll **head)
{
	struct dll *nu,*temp;
	nu=malloc(sizeof(struct dll));
	if(nu==NULL)
	{
		printf("mem not allocated\n");
		return;
	}
	else
	{
		printf("enter data\n");
	//	getchar();
		scanf(" %d",&nu->info);
		nu->next=NULL;
		if(*head==NULL)
		{
			*head=nu;
			nu->prev=NULL;
		}
		else
		{
			temp=*head;
			while(temp->next)
			{	temp=temp->next;
			}
			temp->next=nu;
			nu->prev=temp;

		}

	}


}
