#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
	int info;
	struct queue *next;
};
struct queue *rear=NULL,*front;
void enq(int);
int deq();
int isempty();
void display();
main()
{
	int ch,data;
	while(1)
	{
		printf("1.enq\n2.deq\n3.display\n4.exit\n");
		printf("enter ch:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter data:");
				scanf("%d",&data);
				enq(data);
				break;
			case 2:if(isempty())
				printf("queue is empty\n");
				else
				{	data=deq();
					printf("%d",data);
				}
				break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("invalid ch\n");break;	

		}
	}

}
void enq(int data)
{
	struct queue *nu;
	nu=malloc(sizeof(struct queue));
	
	if(nu==NULL)
		printf("queue is full\n");
	else
	{
		nu->info=data;
		nu->next=NULL;
		if(rear==NULL)
			front=rear=nu;
		else
		{
			rear->next=nu;
			rear=nu;
		}
	}
}
int deq()
{
	int item;
	struct queue *temp;
	temp=front;
	item=temp->info;
	front=front->next;
	free(temp);
	temp=NULL;
	return item;

}
int isempty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}
void display()
{
	struct queue *temp;
	if(isempty())
		printf("queue is empty\n");
	else
	{
		temp=front;
		while(temp)
		{
			printf("%d",temp->info);
			temp=temp->next;
		}
		printf("\n");

	}
}
