#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int i,j;
	puts("enter a");
	gets(a);
	for(i=0;a[i];i++)
		for(j=i+1;a[j];j++)
			if(a[i]==a[j])
			{
				memmove(a+j,a+j+1,strlen(a+j+1)+1);
				j--;
			}
	puts(a);

}
