//////
#include<stdio.h>
#include<string.h>
void input(char (**)[]);
void print(char (*)[]);
void del(char (**)[]);
char *search(char (*)[]);
int cnt=0;
const int MAX=20;
main()
{
	char name[20][20],ch,*temp;
	while(1)
	{
		printf("*****MENU*****\n");
		printf("i-input\np=print\ns-search\nd-delete\ne-edit\nq-quit\n");
		printf("enter ur choice:");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':input(&name);break;
			case 'p':print(name);break;
			case 'd':del(&name);break;
			case 's':temp=search(name);
				printf("found at %u \n",temp);
				break;
			case 'q':return;
			default:printf("invalid i/p\n");return;
		}

	}
}

//////////*********input function*****/////////
void input(char (**p)[20])
{
	if(cnt==MAX)
	{
		printf("memory full\n");
		return;
	}
	printf("enter name:");
	getchar();
	gets(*p[cnt++]);
	return;


}
//////******print function****///////////
void print(char (*p)[20])
{
	int i;
	for(i=0;i<cnt;i++)
		printf("name[%d]=%s %u\n",i,p[i],&p[i]);

}
/////////*********delete function**********////////
void del(char (**p)[20])
{
	char a[20];
	int i;
	if(cnt==0)
	{
		printf("empty database\n");
		return;
	}
	puts("enter name to be del:");
	getchar();
	gets(a);
	for(i=0;i<cnt;i++)
		if(strcmp(*p[i],a)==0)
			break;
	
	if(i==cnt)
	{
		printf("not found\n");
		return;
	}
	
			memmove(*p+i,*p+i+1,(cnt-1-i)*20);
	cnt--;
	printf("name=%s\n",*p[cnt+1]);
}
////////***********search function******///////////
char *search(char (*p)[20])
{
	char a[20],*temp;
	int i;
	printf("enter name to be searchd:");
	getchar();
	gets(a);
	for(i=0;i<cnt;i++)
	{
		if((temp=strstr(p[i],a)));
		{	printf("%u\n",temp);
			return temp;
		}
	}
	if(i==cnt)
	{
	printf("not found\n");
	return 0;
	}




}
