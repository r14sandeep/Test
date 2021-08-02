#include<stdio.h>
#include<string.h>
main()
{
	char s1[100],s2[100];
	char *found;
	int n,i,j,k;
	puts("enter s1");
	gets(s1);
	puts("enter s2");
	gets(s2);
	j=strlen(s2);
	found=s1;
	
/*	while(found=strstr(found,s2))
	{
		k=found-s1;
		j=strlen(s2);
		n=j;
//	printf("%s\n",s2[2]);
//		printf("%d\n",k);
		for(i=k;i<k+j;i++)
		{
	//	printf("%s",s2[3]);
		s1[i]=s2[--n];
		
		}
	//found=found-strlen(s2);
		
	}*/
	while(found=strstr(found,s2))
	{
		k=found-s1;
		for(i=j-1;s2[i];i--)
		{
			s1[k]=s2[i];
			k++;
		}
		found++;
	}



printf("%s\n",s1);
//for(i=0;i<strlen(s2);i++)
//printf("s[%d]=%c",i,s2[i]);

}
