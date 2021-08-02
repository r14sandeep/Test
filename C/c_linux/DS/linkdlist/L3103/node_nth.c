//////prog to insert,delete a node at nth position
#include<stdio.h>
#include<stdlib.h>
struct dll
{
	int info;
	struct dll *prev,*next;	

};
int cnt=0;
void delmiddle(struct dll **);
void addatnth(struct dll **);
void print(struct dll *);
void add(struct dll **);
void delnth(struct dll **);
int main()
{
	struct dll *head=NULL;
	int ch,a;
	while(1)
	{
		printf("1-add\n2-print\n3-addatnth\n4-deletenth\n5-delmiddle\n6-quit\n");
		printf("enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add(&head);break;
			case 2:print(head);break;
			case 3:addatnth(&head);break;
			case 4:delnth(&head);break;
			case 5:delmiddle(&head);break;
			case 6:return;
			default:printf("invalid data\n");break;
		}

	}
	return 0;
}
//////********add function*********/////////

void add(struct dll **head)
{
	struct dll *nu,*temp;
	nu=malloc(sizeof(struct dll));
	if(nu==NULL)
		printf("error in  allocating mem\n");
	else
	{
		printf("enter data:");
		scanf("%d",&nu->info);
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
				temp=temp->next;
			
			temp->next=nu;
			nu->prev=temp;
		}
		cnt++;

	}
}

/////////********print function********//////////
void print(struct dll *head)
{
	struct dll *temp;
	temp=head;
	if(head==NULL)
	{
		printf("no data to print\n");
		return;
	}
	while(temp)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
///////******add at nth position*****/////
void addatnth(struct dll **head)
{
	struct dll *nu,*temp;
	temp=*head;
	nu=malloc(sizeof(struct dll));
	int a,i=1;
	printf("enter position from 1 to %d\n",cnt+1);
	//printf("enter position:");
	scanf("%d",&a);
	if((a==0)||(a>(cnt+1)))
	{	
		printf("invalid position,valid pos from 1 to %d\n",cnt+1);
		return;
	}
	printf("enter data:");
	scanf("%d",&nu->info);
	if(*head==NULL)
	{
		*head=nu;
		nu->prev=NULL;
		cnt++;
	}
	else
	{
		if(a==1)
		{
			*head=nu;
			nu->next=temp;
			nu->prev=NULL;
			temp->prev=nu;
			cnt++;
		}
		else
		{
			for(i=1;i<(a-1);i++)
			{
				temp=temp->next;
			}
			if(temp->next==NULL)
			{
				nu->next=NULL;
				nu->prev=temp;
				temp->next=nu;
				cnt++;
			}
			else
			{
				nu->next=temp->next;
				nu->prev=temp;
				temp->next->prev=nu;
				temp->next=nu;
				cnt++;
			}
		}
		
	}	
}

////////******delete nth node******///////

void delnth(struct dll **head)
{
	struct dll *nu,*temp;
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
				temp->next->prev=NULL;
				*head=temp->next;
				free(temp);
				cnt--;
			}
			else
			{
				for(i=1;i<a;i++)
					temp=temp->next;
				temp->prev->next=temp->next;
				free(temp);
				temp=NULL;
				cnt--;
			}
		}
	}
}

////////////  delete middle node ///////////

void delmiddle(struct dll **head)
{
	struct dll *t=NULL,*p=NULL;
	t=p=*head;
	while(((t->next)!=NULL)&&((t->next->next)!=NULL))
	{
		p=p->next;
		t=t->next->next;
	}
	if(p->prev==NULL)
	{
		if(p->next==NULL)
		{
			*head=NULL;
			free(p);
			p=NULL;
			cnt--;
		}
		else
		{	*head=t->next;
			t->next->prev=NULL;
			free(p);
			p=NULL;
			cnt--;
		}

	}
	else
	if((t->next==NULL)||(t->next->next==NULL))
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		p=NULL;
		cnt--;
	}
}
