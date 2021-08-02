#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10
struct stack
{
	int roll;
	char *name;
	struct stack *next;
};
int top=-1;
void push(struct stack **);
struct stack pop(struct stack **);
int isempty(struct stack *);
void display(struct stack *);
main()
{
	struct stack *top=NULL,*v;
	int ch,data;
	while(1)
	{
		int ch,data;
		printf("\n1-push\n2-pop\n3-display\n");
		printf("enter ch:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(&top);break;
			case 2:if(isempty(top))
					printf("stack is underflow\n");
				else
				{
					v=pop(top);
					printf("%d %s",v->roll,v->name);
				}
				break;
			case 3:display(top);break;
			default:printf("invalid ch\n");break;
		}
	}
}
void push(struct stack **top)
{
	int cnt=0;
	struct stack *nu;
	nu=malloc(sizeof(struct stack));
	if(nu==NULL)
		printf("stack is overflowed\n");
	else
	{
		printf("enter roll:");
		scanf("%d",&nu->roll);
		while(1)
		{
			nu->name=realloc(nu->name,(cnt+1)*sizeof(char));
			nu->name[cnt]=getchar();
			if(nu->name[cnt]=='\n')
			{
				nu->name[cnt]='\0';
				break;
			}
			cnt++;
		}
		nu->next=*top;
		*top=nu;
	}
}
struct stack pop(struct stack *top)
{
	struct stack *temp,v;
	temp=*top;
	top=(top)->next;
	v=temp;
	v.name=malloc(strlen(temp->name)+1);
	strcpy(v.name,temp->name);
	free(temp->name);
	temp->name=NULL;
	free(temp);
	temp=NULL;
	return v;
}
int isempty(struct stack *top)
{
	if(top==NULL)
		return 1;
	else return 0;
}
void display(struct stack *top)
{
	struct stack *temp;
	temp=top;
	while(temp)
	{
		printf("%d %s\n",temp->roll,temp->name);
		temp=temp->next;

	}
}
