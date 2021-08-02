#include<stdio.h>
main()
{
	char s1[][8]={"int","char","float","double"};
	char *s2[]={"INT","CHAR","FLOAT","DOUBLE"};
	char str[]="abc",*ptr="def";
	int i;
	//printf("%s\n",str);
	//printf("%c\n",ptr[1]);
	for(i=0;i<4;i++)
		printf("%s\n",s2[i]);
printf("%u\n",s2);


}
