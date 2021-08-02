#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt=0;
void print(char (*)[]);
void *input(char (*)[]);
void *del(char (*)[]);
main()
{
	char (*buf)[20]=0,ch;
	while(1)
	{
		printf("i-input\np-print\nd-delete\nq-quit\n");
		printf("enter your choice:");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':buf=input(buf);break;
			case 'p':print(buf);break;
			case 'd':buf=del(buf);break;
			case 'q':return;
			default:printf("invlid choice\n");break;

		}

	}
}
void *input(char (*p)[20])
{
	p=realloc(p,(cnt+1)*20);
	puts("enter name:");
	getchar();
	gets(p[cnt++]);
	return p;
}
void print(char (*p)[20])
{
	int i;
	for(i=0;i<cnt;i++)
		printf("name[%d]=%s\n",i,p[i]);

}
void *del(char (*p)[20])
{
	char name[20];
	int i;
	puts("enter name to be deleted:");
	getchar();
	gets(name);
	for(i=0;i<cnt;i++)
	{
		if(strstr(p[i],name))
			break;
	}
	if(i==cnt)
	{
		printf("not found:\n");
		return 0;
	}
	memmove(p+i,p+i+1,(cnt-1)*20);
	//free(p+cnt);
	cnt--;
	return p;



}
