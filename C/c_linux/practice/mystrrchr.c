#include<stdio.h>
char *mystrrchr(char *a,char ch)
{
	int i,j=0;
	for(i=0;a[i];i++)
	{	if(a[i]==ch)
		{
			j=i;
		}
		if((a[i+1]=='\0')&&(a[j]==ch))
			return a+j;
		
	}
	return j;
}
main()
{
	char a[10],ch,*b;
	puts("enter a");
	gets(a);
	puts("enter ch");
	scanf("%c",&ch);
	//b=strrchr(a,ch);
	b=mystrrchr(a,ch);
	printf("%u\n",&a[0]);
	printf("%u\n",b);
	


}
