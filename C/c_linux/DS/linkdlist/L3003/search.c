#include"myheader.h"
struct dll *search(struct dll *head)
{
	//char *p;
	int data;
	struct dll *temp=NULL;
	printf("enter data to be searchd:");
	scanf("%d",&data);
	temp=head;
	while(temp)
	{
		if(temp->info==data)
		{
			if(temp->prev)
			{
			temp=temp->prev->next;
			return temp;
			}
			if(temp->prev==NULL)	
			{
				//printf("data found at %u\n",temp);
				return temp;
			}
		}
		temp=temp->next;
		
	}
	return NULL;
}
