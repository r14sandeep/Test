#include"myheader.h"
void del(struct dll **head)
{
	struct  dll *temp=NULL;
	int data;
//	printf("enter data to be deletd:");
//	scanf("%d",&data);
	if(*head==NULL)
	{
		printf("list is empty\n");
		
	}	
	else
	{
		temp=search(*head);
		if(temp==NULL)
		{
			printf("data not found\n");
		//	return;
		}
		else
		{
			if(temp==*head)
			{
				(*head)=temp->next;
				(*head)->prev=NULL;
			}	
			else
			{
				if(temp->next)
					//temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
				//else
				//	temp->prev->next=NULL;
				temp->prev->next=temp->next;
			}
			free(temp);
			temp=NULL;
	

		}
	}	

}
