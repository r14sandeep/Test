#include<stdio.h>
int main()
{
	char line[100]="abc asdf sdfg";
	char word[10];
//	gets(line);
//	puts(line);
	while(sscanf(line,"%s",word))
	{
//		printf("%c ",word[0]);
		puts(word);
//		line += strl
	}

}
