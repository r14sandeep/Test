//prog to insert,delete a node at nth position
#include<stdio.h>
#include<stdlib.h>
typedef struct cll
{
	int info;
	struct cll *next;	

}NODE;
int cnt=0;
void addatnth(NODE **);
void print(NODE *);
void add(NODE **);
void delnth(NODE **);
void del_middle(NODE **);
main()
{
	NODE *head=NULL;
	int ch,a;
	while(1)
	{
	printf("1-add\n2-print\n3-addatnth\n4-deletenth\n5-del middle node\n6-quit");
	printf("enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:add(&head);break;
		case 2:print(head);break;
		case 3:addatnth(&head);break;
		case 4:delnth(&head);break;
		case 5:del_middle(&head);break;
		case 6:break;
		default:printf("invalid choice\n");break;
	}

	}
}
//////********add function*********/////////

void add(NODE **head)
{
	NODE *nu,*temp;
	nu=malloc(sizeof(NODE));
	if(nu==NULL)
		printf("error in  allocating mem\n");
	else
	{
		printf("enter data:");
		scanf("%d",&nu->info);
		
		if(*head==NULL)
		{
			*head=nu;
			nu->next=nu;
			cnt++;
		}
		else
		{
			temp=*head;
			while(temp->next)
			{
				if(temp->next==(*head))
				{
					temp->next=nu;
					nu->next=(*head);
					cnt++;
					return;
				}
				temp=temp->next;
			}
			cnt++;
		}

	}
}

/////////********print function********//////////
void print(NODE *head)
{
	NODE *temp;
	temp=head;
	if(head==NULL)
	{
		printf("no data to print\n");
		return;
	}
	printf("%u\n",head);
	while(temp)
	{
		printf("%u %d %u\n",temp,temp->info,temp->next);
//		printf("%d\n",temp->info);
		if(temp->next==head)
			return;
		temp=temp->next;
	}
}
///////******add at nth position*****/////
void addatnth(NODE **head)
{
	NODE *nu,*temp,*prev;
	temp=*head;
	prev=*head;
	nu=malloc(sizeof(NODE));
	int a,i;
	printf("enter data:");
	scanf("%d",&nu->info);
	if(*head==NULL)
	{
		*head=nu;
		nu->next=nu;
		cnt++;
	}
	else
	{
		printf("enter position:");
		scanf("%d",&a);
		if((a==0)||(a>(cnt+1)))
			printf("invalid position,valid pos from 1 to %d\n",cnt+1);
		else
		{
			if(a==1)
			{
				while(temp=temp->next)
				{
					if(temp->next==*head)
					{
						temp->next=nu;
						nu->next=prev;
						*head=nu;
						cnt++;
						return;
					}

				}
			}
			else
			{
				for(i=1;i<a;i++)
				{
					prev=temp;
					temp=temp->next;
				}
				/*if(temp==*head)
				{
					prev->next=nu;
					nu->next=temp;
				}*/
				
				prev->next=nu;
				nu->next=temp;
				cnt++;
			}
		}
	}	
}

////////******delete nth node******///////

void delnth(NODE **head)
{
	NODE *nu,*temp,*prev;
	prev=*head;
	int a,i;
	temp=*head;
	if(*head==NULL)
		printf("no data present\n");
	else
	{
		printf("enter position to be deleted:");
		scanf("%d",&a);
		if((a==0)||(a>cnt))
			printf("invalid node:enter between 1 to %d\n",cnt);
		else
		{
			if(a==1)
			{
				while(temp=temp->next)
				{	
					if(temp->next==*head)
					{
						temp->next=prev->next;
						*head=prev->next;
						free(prev);
						prev=NULL;
						cnt--;
						if(cnt==0)
							*head=NULL;
						return;
					}
				}
			}
			else
			{
				for(i=1;i<a;i++)
				{
					prev=temp;
					temp=temp->next;

				}
				if(temp->next==*head)
				{
					prev->next=*head;
					free(temp);temp=NULL;
				}
				else
				{
					prev->next=temp->next;
					free(temp);
					temp=NULL;
				}

				cnt--;
			}
		}
	}
}
///////////////////delete middle node////////

void del_middle(NODE **head)
{
	NODE *temp,*p,*q;
	p=*head;q=*head;temp=*head;
	while((q->next!=*head)&&(q->next->next!=*head))
	{
		temp=p;
		p=p->next;
		q=q->next->next;
	}
	if(q->next==*head)
	{
		temp->next=p->next;
		free(p);
		p=NULL;

	}	
	if(q->next->next==*head)
	{
		temp->next=p->next->next;
	//	free(p->next);
		//p->next=NULL;
		free(p);
		p=NULL;
	
	}
}
