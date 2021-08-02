#include<stdio.h>
main()
{
	char s1[][10]={"int","char","float","double"};
	char *s2[]={"INT","CHAR","FLOAT","DOUBLE"};
	char str[]="ABC";
	char *ptr="DEF";
	printf("%s\n",str);
	printf("%s\n",ptr);
	printf("%c\n",str[1]);
	printf("%c\n",ptr[1]);
	printf("%c\n",*str);
	printf("%c\n",*ptr);


}
