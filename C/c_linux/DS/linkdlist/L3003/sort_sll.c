#include<stdio.h>
#include<stdlib.h>
typedef struct sll
{
	int info;
	struct sll *next;

}SLL;
int cnt=0;
void add(SLL **);
void reverse(SLL **);
void print(SLL *);
int main()
{
	SLL *head;
	int ch;
	while(1)
        {
                printf("1-add\n2-print\n3-reverse\n");
                printf("enter ur choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:add(&head);break;
			case 2:print(head);break;
			case 3:reverse(&head);break;
		}

	}

}


void add(SLL **head)
{
        SLL *nu,*temp;
        nu=malloc(sizeof(SLL));
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
        cnt++;
}
	
void reverse(SLL **head)
{
	SLL *temp1,*temp2,*temp3;
	int i,j;
	temp1=*head;
	temp2=(*head)->next;
	for(i=0;i<cnt-1;i++)
		for(j=i+1;j<cnt;j++)
			if(temp1->info>temp2->info)
			{
				temp1->next=temp2->next->next;
				temp2->next=temp1;
				*head=temp2;
				temp3=temp1;
				temp1=temp2;
				temp2=temp3->next;
				printf("*\n");
			}
			else
			{
				temp2=temp2->next;
				printf("*e\n");
				if(temp2->next!=NULL)
				temp2=temp2->next;
				else
					break;
			}
	*head=temp1;
}
void print(SLL *head)
{
        SLL *temp;
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

