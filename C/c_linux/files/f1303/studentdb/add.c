#include"myheader.h"
#include<signal.h>
void save(STUDENT *,int);
void add(STUDENT **ptr,int *cnt)
{
	(*ptr)=(STUDENT *)realloc((*ptr),sizeof(STUDENT)*(*cnt+1));
	printf("enter roll:");
	scanf("%d",&(*ptr+*cnt)->roll);
	printf("enter name:");
	getchar();
	gets(( *ptr+*cnt)->name);
	printf("enter mark:");
	scanf("%f",&(*ptr+*cnt)->mark);
	++*cnt;
	signal(SIGALRM,save);
	alarm(5);	
	return;
}
