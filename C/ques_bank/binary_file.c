#include<stdio.h>
int main()
{
	FILE *fp;
	int cnt=0,cnt2=0;
	char ch;
	fp=fopen("a.out","rb");
	while((ch=fgetc(fp))!=EOF)
	{
			printf("%c\n",ch);
		if(ch=='1')
		{	cnt++;
			printf("%c\n",ch);
		}
		else
			cnt2++;
	}
	printf("\n%d\n",cnt);
}
