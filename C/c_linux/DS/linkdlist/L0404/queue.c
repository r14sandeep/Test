#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear,front;
int queue[MAX];
void enq(int);
int deq();
int isempty();
int isfull();
void display();
main()
{
	int ch,data;
	rear=front=-1;
	while(1)
	{
		printf("1.enq\n2.deq\n3.display\n4.exit\n");
		printf("enter ch:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter data:");
				scanf("%d",&data);
				if(isfull())
					printf("queue is full\n");
				else
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
	if(front==-1)
		front++;
	rear++;
	queue[rear]=data;
}
int deq()
{
	int item;
	item=queue[front];
	front++;
	if(front==MAX)
		rear=front=-1;
	return item;

}
int isempty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;

}
void display()
{
	int i=front;
	while(i<=rear)
	{
		printf("%d",queue[i]);
		i++;	

	}

}
