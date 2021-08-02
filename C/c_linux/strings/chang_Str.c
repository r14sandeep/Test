#include<stdio.h>
int main()
{
	char list[26]="qwertyuiopasdfghjklzxcvbnm";
	char alpha[26]="abcdefghijklmnopqrstuvwxyz";
	char str[10],res[10];
	int i,ind,j;
	puts("enter a string:");
	gets(str);
	for(i=0;str[i];i++)
	{
		for(j=0;list[j];j++)
			if(str[i]==list[j])
			{
				ind=j;
				res[i]=alpha[ind];
			}
			
	}
	res[i]='\0';
	puts(res);

}
