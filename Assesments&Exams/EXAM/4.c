#include<stdio.h>
#include<stdlib.h>
int main()
{
	char string[20];
	int index1,index2;
	puts("enter a string:");
	gets(string);
	for(index1=0;string[index1];index1++)
	{
		for(index2=0;string[index2];index2++)
			if((string[index1]==string[index2])&&(index1!=index2))
				break;
		if(string[index2]=='\0')
		{
			printf("first non repeating char in string %s is:%c\n",string,string[index1]);
			return 0;
		}
	}
	printf("first non repeating char in string %s is:-1\n",string);
	
}
