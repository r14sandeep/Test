#include<stdio.h>
#include<unistd.h>
int main()
{
	int ch;
	printf("1.sum\n2.fact\n");
	printf("enter your choice:");
	scanf("%d",&ch);
	if(ch==1)
		execlp("./sum","./sum",NULL);
	else
		execlp("./fact","./fact",NULL);
}
