#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int info;
	struct sll *next;

};
void add(struct sll **);
void print(struct sll *);
void printmiddle(struct sll *);
int main()
{
	struct sll *head=NULL;
	int ch,cnt=0;
	while(1)
//	while(cnt<5)
	{
		printf("1-add\n2-print\n3-printmiddle\n");
		printf("enter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add(&head);break;
			case 2:print(head);break;
			case 3:printmiddle(head);break;
			default:printf("invalid data\n");break;

		}
//		cnt++;
	}
//	free(head);
//	head=NULL;
//	printf("%d\n",head->next->info);
}
void add(struct sll **head)
{
	struct sll *nu,*temp;
	nu=malloc(sizeof(struct sll));
	printf("enter info:");
	scanf("%d",&nu->info);
	nu->next=NULL;
	if(*head==NULL)
		*head=nu;
	else
	{
		temp=*head;
		while(temp->next)
			temp=temp->next;
		temp->next=nu;
	}	
}

void print(struct sll *head)
{
	struct sll *temp;
	temp=head;
	if(head==NULL)
		printf("no data to print:\n");
	else
	{
		while(temp)
		{
			printf("%d\n",temp->info);
			temp=temp->next;
		}

	}

}
void printmiddle(struct sll *head)
{
	struct sll *temp,*p,*q;
	p=head;q=head;temp=head;
	while((q->next)&&(q->next->next))
	{
		p=p->next;
		q=q->next->next;

	}
	if(q->next==NULL)
		printf("middle node is %d\n",p->info);
	else 
		if(q->next->next==NULL)
		printf("middle nodes are %d %d\n",p->info,p->next->info);
}
