#include"header.h"
void del1stnode(NODE **head)
{
	NODE *temp;
	temp=*head;
	if(*head==NULL)
		printf("no data to del\n");
	else
	{
		*head=temp->next;
		free(temp);
	}

}
