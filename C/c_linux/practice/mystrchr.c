#include<stdio.h>
char *mystrchr(char *a,char ch)
{
	int i;
	for(i=0;a[i];i++)
		if(a[i]==ch)
			return a+i;
	return 0;

}
main()
{
	char a[100],ch,*b;
	puts("enter a");
	gets(a);
	puts("enter ch");
	scanf("%c",&ch);
	/*b=strchr(a,ch);
	printf("%u\n",&a[0]);
	printf("%u\n",b);*/
	b=mystrchr(a,ch);
	printf("%u\n",&a[0]);
	printf("%u\n",b);

}

