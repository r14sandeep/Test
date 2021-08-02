#include<stdio.h>
#include<string.h>
struct db
{
	char name[20];
	char contact[20];

};
void input(struct db *);
void print(struct db *);
void sort(struct db *);
void del(struct db*);
int cnt=0;

main()
{
	struct db v[20];
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
	case 'd':del(v);break;
	default:printf("invalid option\n");break;	
	}

	}
}
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
	char temp1[20],temp2[20];
	int i,j;
	for(i=cnt-1;i>=0;i--)
		for(j=0;j<i;j++)
			if((p+j)->name[0]>(p+j+1)->name[0])
			{
				//char temp1[20],temp2[20];
				strcpy(temp1,(p+j)->name);
				strcpy(temp2,(p+j)->contact);
				strcpy((p+j)->name,(p+j+1)->name);
				strcpy((p+j)->contact,(p+j+1)->contact);
				strcpy((p+j+1)->name,temp1);
				strcpy((p+j+1)->contact,temp2);
	
			}



}
void del(struct db *p)
{
	char name2del[20];
	int i;
	puts("name 2 b deleted\n");
	getchar();
	gets(name2del);
	for(i=0;i<cnt;i++)
	{	if(strstr((p+i)->name,name2del))
			memmove(p+i,p+i+1,(cnt-i-1)*sizeof(struct db));
		if(i==cnt)
		{	printf("not found\n");
			return;}
	}
	cnt--;

}
