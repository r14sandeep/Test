#include"myheader.h"
void reverse(struct dll **head)
{
	struct dll *temp1,*temp2,*p,*q;
	temp1=*head; 
	//int d;
	p=*head;
	while(temp1->next)
	{
		temp1=temp1->next;
	}
	if(temp1->next==NULL)
		q=temp1;
	temp1=*head;
	//*head=q->prev;
	while((p!=q)&&(p!=q->next))
	{
		temp1=p;
		temp2=q;
		p->next=q->prev;
		p->prev=q->next;
		p->info=q->info;
		q->next=temp1->prev;
		q->prev=temp1->next;
		q->info=temp1->info;
		p=temp1->next;
		q=temp2->prev;
	}




}
