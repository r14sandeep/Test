#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct db
{
	char name[20];
	char contact[20];
};
void input(struct db *);
void print(struct db *);
void del(struct db *v);
int cnt=0;
main()
{
	struct db v;
	char ch;
	while(1)
	{
		printf("i-input\np-print\nd-delete\nq-quit\n");
		printf("enter your choice:");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':input(&v);break;
			case 'p':print(&v);break;
			case 'd':del(&v);break;		


		}

	}

}
void input(struct db *v)
{
	int i;
	printf("enter name:");
	scanf("%s",(v+cnt)->name);
	printf("enter no:");
	scanf("%s",(v+cnt)->contact);
	cnt++;
}
void print(struct db *v)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		printf("%-20s %-20s\n",(v+i)->name,(v+i)->contact);
	}
}
void del(struct db *v)
{
	char a[20];
	int i;
	puts("enter name to be deleted:");
	getchar();
	gets(a);
	for(i=0;i<cnt;i++)
	{
		if(strstr((v+i)->name,a))
			break;
	}
	if(i==cnt)
	{
		puts("not found");return;
	}
	memmove(v+i,v+i+1,(cnt-i-1)*sizeof(struct db));
	cnt--;


}
