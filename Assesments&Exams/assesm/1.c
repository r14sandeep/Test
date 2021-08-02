#include<stdio.h>
#include<stdlib.h>
typedef struct sll
{
	int data;
	struct sll *next;

}NODE;
int n1=0,n2=0,n3=0,n4=0,n5=0;
void add(NODE **head)
{
	NODE *temp,*nu;
	nu=malloc(sizeof(NODE)*1);
	printf("enter value:");
	scanf("%d",&(nu->data));
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

void print(NODE *head)
{
	while(head)
	{
		printf("%d->",head->data);
		head=head->next;

	}
	printf("\n");
}

void change(NODE **head,int data)
{
	NODE *temp,*prev;
	temp=*head;
	while(temp)
	{
		if((temp->data==data)&&(temp!=*head))
		{
			prev->next=temp->next;
			temp->next=(*head);
			*head=temp;
			break;
		}
		prev=temp;
		temp=temp->next;
	}	

}
void change_to(NODE **head,int data,int first)
{
	NODE *temp,*prev,*temp2=NULL,*temp3=NULL;
	temp=prev=*head;
	temp2=temp3=*head;
	while(temp)
        {
		if(temp->data==first)
		{
			temp3=temp;
			temp2->next=temp->next;
		}
                if(temp->data==data)
                {
                        prev->next=temp->next;
			temp->next=temp2->next;
                        temp3->next=temp;
                        break;
                }
		
                prev=temp;
                temp=temp->next;
        }



}
void search(NODE **head,int data)
{
	NODE *temp,*prev;
	temp=prev=*head;
/////

if(data==1)
{
if(n1>=n2)	
	if(n1>=n3)	
		if(n1>=n4)	
		{
			if(n1>=n5)	
				change(head,data);

			else
			change_to(head,data,5);
				
		}
		else		
			change_to(head,data,4);
}
if(data==3)
{
if(n3>=n1)	
	if(n3>=n2)	
	{
		if(n3>=n4)	
			if(n3>=n5)	
				change(head,data);
	}
	else
		change_to(head,data,2);

}



/////

if(data==4)
{
if(n4>=n1)	
if(n4>=n2)	
if(n4>=n3)	
if(n4>=n5)	
	change(head,data);
}
if(data==5)
{
if(n5>=n1)	
	if(n5>=n2)	
		if(n5>=n3)	
		{
			if(n5>=n4)	
				change(head,data);
			else
				change_to(head,data,4);
		}
		else
			change_to(head,data,3);

}
if(data==2)
{
if(n2>=n1)	
if(n2>=n3)	
if(n2>=n4)	
if(n2>=n5)	
	change(head,data);
else
	change_to(head,data,5);

}

}



int main()
{
	NODE *head=NULL;
	int ch,data,cnt=0,*arr;
	while(1)
	{
	printf("1.add \n2.print\n3.search\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:add(&head);break;
		case 2:
//			search(&head,data);
			print(head);break;
		case 3:
			
			printf("enter the data to be searched:");
			scanf("%d",&data);
			
			if(data==1)
			{	
				n1++;
			}
			else if(data==2) 
			{	
				n2++;
			}
			else if(data==3)
			{
				n3++;
			}
			else if(data==4) 
			{
				n4++;
			}
			else if(data==5) 
			{
				n5++;
			}
			search(&head,data);
			break;
		case 4:return 0;
		default:printf("invalid\n");break;			

	}
	}

}
