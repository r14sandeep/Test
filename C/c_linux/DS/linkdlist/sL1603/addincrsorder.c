#include"header.h"
void add(NODE **head)
{
	NODE *nu,*temp,*prev;
	int cnt=0;
	temp=*head;
	prev=*head;
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
		if(temp->next==NULL)
		{
			if((temp->roll)>(nu->roll))	
			{
				*head=nu;
				nu->next=temp;

			}	
			else
			{
				temp->next=nu;
				nu->next=NULL;
			}
		}
		else
		{
			while(temp)
			{
				if((temp->roll)>(nu->roll))	
				{
					cnt++;
					if(*head==temp)
					{
						nu->next=temp;
						*head=nu;
						return;
					}
					else
					{	prev->next=nu;
						nu->next=temp;
						return;
					}
				}
				prev=temp;
				temp=temp->next;
			}
			if(cnt==0)
			{
				prev->next=nu;
				nu->next=NULL;

			}
		}			
		

	}


}
