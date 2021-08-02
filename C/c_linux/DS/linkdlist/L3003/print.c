#include"myheader.h"
void print(struct dll *head)
{
	struct dll *temp;
	temp=head;
	while(temp)
	{
		printf("%d\n",temp->info);
		temp=temp->next;

	}


}
