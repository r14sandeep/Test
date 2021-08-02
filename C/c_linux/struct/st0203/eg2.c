#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct db
{
	char name[20];
	char contact[20];

};
void input(struct db***);
void print(struct db**);
void del(struct db***);
//struct db*sort(struct db*);
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
		case 'i':input(&buf);break;
		case 'p':print(buf);break;
	//	case 'd':del(&buf);break;
//		case 's':buf=sort(buf);break;
		case 'q':return;
		default:printf("invalid input\n");break;

	}
	}
}
void input(struct db ***p)
{
	(*p)=(struct db**)realloc((*p),(cnt+1)*sizeof(struct db*));
	*p[cnt]=(struct db*)malloc(100);
	printf("enter a name\n");
	getchar();
	gets((*p[cnt])->name);
	puts("enter no:");
	gets((*p[cnt])->contact);
	cnt++;
	return;
}
void print(struct db **p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%-20s %-20s\n",(*p+i)->name,(*p+i)->contact);

}
/*void del(struct db ***p)
{
	char name2del[20];
	int i;
	printf("enter name 2 b deleted\n");
	getchar();
	gets(name2del);
	for(i=0;i<cnt;i++)
	{
		if(strcmp((*p+i)->name,name2del))
		//	memove((*p+i),(*p+i+1),(cnt-i-1)*sizeof(struct db *));
			break;
	}
	if(i==cnt)
	{
		printf("not found\n");
		return;

	}
	
	memove((*p+i),(*p+i+1),(cnt-i-1)*sizeof(struct db *));
	cnt--;
	*p=(struct db*)realloc(*p,cnt*sizeof(struct db));
}
struct db*sort(struct db *p)
{
	struct temp *q;
	int i,j;
	for(i=cnt-1;i>=0;i++)
		for(j=0;j<i;j++)
			if((strcmp((p+j)->name,(p+j+1)->name))>0)
			{
				q=(p+j);
				p[j]=p[j+1];
				(p+j+1)=q;
			}
		


	return p;



}*/
