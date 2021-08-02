#include<stdio.h>
int mystrcasecmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i],b[j];i++,j++)
	{
		if(!((a[i]-b[j]==32)||(a[i]-b[j]==0)))
		{
			if(a[i]>b[j])
				return 1;
			else
				return -1;

		}
	}
	return 0;

}

main()
{
	char a[10],b[10];
	int i;
	puts("enter a,b");
	gets(a);
	gets(b);
	i=mystrcasecmp(a,b);
	printf("%d\n",i);

}
