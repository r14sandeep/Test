#include<stdio.h>
#include<string.h>
void input(char (*)[2][20]);
void print(char (*)[2][20]);
int cnt=0;
const int MAX=20;
main()
{
	char contact[20][2][20],ch;
	while(1)
	{
		printf("*****MENU*****\n");
		printf("i-input\np-print\nd-delete\ns-sort\nq-quit\n");
		printf("enter ur choice\n");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':input(contact);break;
			case 'p':print(contact);break;
//			case 'd':del(contact);break;
//			case 's':sort(contact);break;
			case 'q':return;
			default:printf("invalid data\n");return;
		}

	}


}
void input(char (*p)[2][20])
{
	int i;
	if(cnt==MAX)
	{
		printf("mem full\n");
		return;
	}
	printf("enter name:");
	getchar();
	gets(p[cnt][0]);
	puts("enter numbr:");
	gets(p[cnt][1]);
	cnt++;


}
void print(char (*p)[2][20])
{
	int i,j;
	for(i=0;i<cnt;i++)
	{	for(j=0;j<2;j++)
		printf("%-20s ",p[i][j]);
		printf("\n");
	}
}
