#include"myheader.h"
void add(NODE **ptr)
{
	NODE *nu;
	nu=(NODE *)malloc(sizeof(NODE));
	printf("enter roll");
	scanf("%d",&(nu->next));
	printf("enter name");
	getchar();
	scanf("%s",&(nu->name));
	printf("enter mark");
	scanf("%s",&(nu->mark));
	if(*ptr==0)
	{
		nu->next=NULL;
		(*ptr)=nu;

	}
	//here head pointed to last entered data

	else
	{
		nu->next=(*ptr);
		(*ptr)=nu;

	}
	

	return;


}
