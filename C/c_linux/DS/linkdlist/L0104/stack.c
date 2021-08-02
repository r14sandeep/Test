#include<stdlib.h>
#include<stdio.h>
#define MAX 10
int top=-1;
int arr[MAX];
void push(int );
void display();
int pop();
int isempty();
int isfull();
int main()
{
	while(1)
	{
		int ch,data;
		printf("\n1-push\n2-pop\n3-display\n");
		printf("enter ch:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the data:");
				scanf("%d",&data);
				if(isfull())
					printf("stack overflowd\n");
				else
					push(data);
				break;
			case 2:if(isempty())
					printf("stack is underflow\n");
				else
				{
					data=pop();
					printf("%d",data);
				}
				break;
			case 3:display();break;
			default:printf("invalid ch\n");break;
		}
	}
}
void push(int data)
{
	top++;
	arr[top]=data;

}
int pop()
{
	int item;
	item=arr[top];
	top--;
	return item;

}
int isfull()
{
	if(top==MAX-1)
		return 1;
	else return 0;
}
int isempty()
{
	if(top==-1)
		return 1;
	else return 0;
}
void display()
{
	int i;
	if(top==-1)
	printf("stack is empty\n");
	else
	{
		for(i=0;i<=top;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
}
