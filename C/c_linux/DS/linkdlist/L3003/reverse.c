#include"myheader.h"
void reverse(struct dll **head)
{
	struct dll *temp,*p,*q;
	temp=*head; 
	int d;
	p=*head;
	while(temp->next)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
		q=temp;
	temp=*head;
	while((p!=q)&&(p!=q->next))
	{
		d=p->info;
		p->info=q->info;
		q->info=d;
		p=p->next;
		q=q->prev;

	}




}
