#include<stdio.h>
#include<string.h>
struct db
{
	char name[20];
	char contact[20];

};
char *search(struct db *);
void del(struct db *);
void input(struct db *);
void print(struct db *);
void sort(struct db *);
int cnt=0;

main()
{
	struct db v[20];
	char *temp=NULL;
	
	char ch;
	

	while(1)
	{
	printf("*****MENU****\n");
	printf("i-input\np-print\nd-delete\ns-sort\nq-quit\n");
	printf("enter ur choice");
	scanf(" %c",&ch);
	switch(ch)
	{
	case 'i':input(v);break;
	case 'p':print(v);break;
	case 's':sort(v);break;
	case 'f':temp=search(v);
		if(temp)
			printf("found at %u\n",temp);
		else
			printf("not found\n");break;
	case 'q':return;
	case 'd':del(v);break;
	default:printf("invalid option\n");break;	
	}

	}
}
///////*********input function****/////////

void input(struct db *p)
{
	printf("enter name\n");
	getchar();
	gets(p[cnt].name);
	printf("enter no\n");
	gets((p+cnt)->contact);
	cnt++;
	return;

}
void print(struct db *p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%-20s %-20s\n",(p+i)->name,(p+i)->contact);
	//printf("abcd\n");
}
void sort(struct db *p)
{
	struct db temp;
	int i,j;
	for(i=cnt-1;i>=0;i--)
		for(j=0;j<i;j++)
			if((p+j)->name[0]>(p+j+1)->name[0])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;				
			}



}
char *search(struct db *p)
{
	char name[20];
	int i;
	char *found;
	printf("enter name to be searched:\n");
	getchar();
	gets(name);
	for(i=0;i<cnt;i++)
	{
		if(found=strstr(p[i].name,name))
			return found;
	}
	if(i==cnt)
	{	//printf("not found\n");
		return NULL;
	}
	

}
void del(struct db *p)
{
	char name[20];
//	char *found;
	int i;
	puts("enter name to be deleted:");
	getchar();
	gets(name);
	for(i=0;i<cnt;i++)
	{
		if(strstr(p[i].name,name))
			//memmove(found,found+1,(cnt-1-i)*(sizeof(struct db)));
			break;
	}
	if(i==cnt)
	{
		printf("not found\n");
		return;
	}
	memmove(p+i,p+i+1,(cnt-1-i)*(sizeof(struct db)));
	cnt--;

}

