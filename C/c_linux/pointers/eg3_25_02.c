#include<stdio.h>
main()
{
	char str[][8]={"int","char","float","double"};
	char *p[4]={str[0],str[1],str[2],str[3]},**ptr=p;
	
	int i;
	printf("%u\n",&ptr);
	printf("%s\n",p[0]);
	printf("%s\n",str[0]);

//	printf("%u\n",&p);





}
