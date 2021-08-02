#include"myheader"
void print(NODE *ptr)
{
	while(ptr)
	{
		printf("%-4d%-20s %0.2f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}




}
