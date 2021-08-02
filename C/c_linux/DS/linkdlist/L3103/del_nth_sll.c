#include<stdio.h>
#include<stdlib.h>
typedef struct sll
{
	int info;
	struct sll *next;

}NODE;
int cnt=0;
void add(NODE **);
void del_middle(NODE **);
void reverse(NODE **);
NODE *recursiveReverse(NODE *);
void print(NODE *);
void printmiddle(NODE *);
void delnth(NODE **);
void pallindrom(NODE *);
NODE *temp1;
main()
{
	NODE *head=NULL;
	int ch;
	while(1)
	{
		printf("\n1-add\n2-print\n3-printmiddle\n4-del nth node\n5-delmiddle\n6-pallindrom\n7-reverse\n");
		printf("enter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add(&head);break;
			case 2:print(head);break;
			case 3:printmiddle(head);break;
			case 4:delnth(&head);break;
			case 5:del_middle(&head);break;
			case 6:pallindrom(head);break;
			//case 7:temp1=head;reverse(&head);break;
			case 7:head=recursiveReverse(head);break;
			default:printf("invalid choice\n");break;

		}
	}
}
////////////////add node(in the last)//////////

void add(NODE **head)
{
	NODE *nu,*temp;
	nu=malloc(sizeof(NODE));
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
/////////////////      print       ////////////
void print(NODE *head)
{
	NODE *temp;
	temp=head;
	if(head==NULL)
		printf("no data to print:\n");
	else
	{
		while(temp)
		{
			printf("%d -> ",temp->info);
			temp=temp->next;
		}

	}
	printf("\n");

}

//////////print middle node////////////

void printmiddle(NODE *head)
{
	NODE *temp,*p,*q;
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
/////////delete nth node////////////

void delnth(NODE **head)
{
	NODE *temp,*prev;
	
	int a,i;
	temp=*head;
	printf("enter node position to be deleted:");
	scanf("%d",&a);
	if((a==0)||(a>cnt))
	{
		printf("invalid node..it should be from 1 to %d\n",cnt);
		return;
	}
	if(a==1)
	{
		*head=temp->next;
		free(temp);
		temp=NULL;
		cnt--;
	}
	else
	{
		for(i=1;i<a;i++)
		{
			prev=temp;
			temp=temp->next;
			
		}
		prev->next=temp->next;
		free(temp);
		temp=NULL;
		cnt--;
	}
}
//////////// delete middle node //////////////

void del_middle(NODE **head)
{
	NODE *p,*q,*temp;
	p=q=*head;
	if((*head==NULL))
	{
		printf("no data to delete\n");
		return;
	}
	if(p->next==NULL)
	{
		printf("only one node is available\n");return;
	}
	if(p->next->next==NULL)
	{
		printf("only two nodes are available\n");return;
	}
	
	while((q->next)&&(q->next->next))
	{
		temp=p;
		p=p->next;
		q=q->next->next;
	}
	temp->next=p->next;
	cnt--;
	free(p);
	p=NULL;
}
///////////reverse//////////////

/*void reverse(NODE **head)
{
	 NODE *p,*q,*temp;
	while(cnt/2)
	{
		for(i=0;i<0;i++)
			p=p->next;
		for(j=0;j<cnt-i;j++)
			q=q->next;
		temp=p;
		p->info=q->info;
		p->next=q->next;


	}


}*/

///////pallindrom//////////////////

void pallindrom(NODE *head)
{
	NODE *p,*q;
	p=q=head;
	int k=0,i,j;
	if(head==NULL)
	{
		printf("no data present\n");return;
	}
	if(cnt==1)
	{
		printf("only one data present\n");return;
	}
 	while(k<(cnt/2))
	{
		p=q=head;
		for(i=0;i<k;i++)
			p=p->next;
		for(j=0;j<(cnt-k-1);j++)
			q=q->next;
		if(p->info==q->info)
			k++;
		else
		{
			printf("not pallindrom\n");return;
		}

	}
	printf("pallindrom\n");
}
/*void pall(NODE *head)
{
	if(head->next)
	pallendrom(head->next);
	if(head->info!=prev->info)
	{
		printf("not a pallindrom\n");exit(0);
	}
	if((head==prev)||(prev->next==head))
	{
		printf("pallendrom\n");exit(0);

	}
	prev=prev->next;



}*/
void reverse(NODE **head)
{
	NODE *temp2;
	temp2=*head;
	if(temp2->next!=NULL)
		reverse(&(temp2->next));
	else
		if((temp2!=temp1)&&(temp2->next!=temp1))
		{
			int val;
			val=temp1->info;
			temp1->info=temp2->info;
			temp2->info=val;
			temp1=temp1->next;
		}
}

int count = 0;
NODE *recursiveReverse(NODE *list)
{
    NODE *revHead;
    if (list == NULL || list->next == NULL)
    {
        return list;
    }

    revHead = recursiveReverse(list->next);
//    printf("count %d list-> info %d\n",count,list->info);
    list->next->next = list;
    list->next = NULL; 
//    count++;
    return revHead;
}
