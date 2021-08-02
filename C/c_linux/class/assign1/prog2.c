//prog to print binary equi of given char
#include<stdio.h>
main()
{
	int bit,a;
	char ch;
	printf("enter a char:");
	scanf("%c",&ch);
	
	bit=sizeof(char)*8-1;
loop:
	if(bit>=0){
	  printf("%d",(ch>>bit)&1);
	  bit--;
	  goto loop;}

}
