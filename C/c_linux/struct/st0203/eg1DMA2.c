#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct db
{
	char name[20];
	char contact[20];

};
struct db **input(struct db**);
void print(struct db**);
struct db** del(struct db**);
//void sort(struct db*);
int cnt=0;
main()
{
	struct db **buf=NULL;
	
	char ch;
	while(1)
	{
	printf("*****MENU****\n");
	printf("i-input\np-print\nd-delete\ns-sort\nq-quit\n");
	printf("enter ur choice\n");	
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'i':buf=input(buf);break;
		case 'p':print(buf);break;
		case 'd':buf=del(buf);break;
//		case 's':sort(&buf);break;
		case 'q':return;
		default:printf("invalid input\n");break;

	}
	}
}
struct db**input(struct db **p)
{
	*p=(struct db*)realloc(*p,(cnt+1)*sizeof(struct db*));
	(*p+cnt)=malloc(sizeof(struct db));
	printf("enter a name\n");
	getchar();
	gets((*p+cnt)->name);
	puts("enter no:");
	gets((*p+cnt)->contact);
	cnt++;
	return p;
}
void print(struct db **p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%-20s %-20s\n",p[i]->name,p[i]->contact);

}
struct db**del(struct db **p)
{
	char name2del[20];
	int i;
	printf("enter name 2 b deleted\n");
	getchar();
	gets(name2del);
	for(i=0;i<cnt;i++)
	{
		if(strcmp((*p+i)->name,name2del))
			memmove((*p+i),(*p+i+1),(cnt-i-1)*sizeof(struct db *));
		if(i==cnt)
		{
			printf("not found\n");
			return;

		}
	
	cnt--;
	*p=(struct db*)realloc(*p,cnt*sizeof(struct db));
	return p;

	}


}
/*void sort(struct db **p)
{
	struct temp q[1];
	int i,j;
	for(i=cnt-1;i>=0;i++)
		for(j=0;j<i;j++)
			if((strcmp((*p+j)->name,(*p+j+1)->name))>0)
			{
				q=*p[j];
				*p[j]=*p[j+1];
				*p[j+1]=q;
			}
		


//	return p;



}*/
