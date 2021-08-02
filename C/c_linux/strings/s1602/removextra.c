///w.a.p to remove extra repetations in a given string
#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int n,i,j;
	puts("enter a string:");
	gets(a);
	puts(a);
	//fgets(a,100,stdin);
	//a[strlen(a)-1]='\0';
	n=strlen(a);
	for(i=0;a[i];i++)
	{
		for(j=i+1;a[j];j++)
			if(a[i]==a[j])
			{
				memmove(a+j,a+j+1,strlen(a+j+1)+1);
				j--;
			}

	}
	printf("%s\n",a);
}
