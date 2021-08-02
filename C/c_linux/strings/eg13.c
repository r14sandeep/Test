/****implement strstr****/
#include<stdio.h>
char *vstrstr(char *,char *);
main()
{
	char s1[]="abcdeaxyzabcdxyz";
	char s2[]="xyz",*ptr;
	ptr=vstrstr(s1,s2);
//	if(ptr==NULL)
//		printf("not found\n");
//	else
//		printf("found at %d\n",ptr-s1);
}
char *vstrstr(char *s1,char *s2)
{
	int i,k,j=0;
	k=strlen(s1);
	for(i=0;i<k;i++)
	{
		if(s2[j]==s1[i])
			j++;
		if(s2[j]=='\0')
		{
			printf("found at %d\n",i-j+1);
			j=0;
			//return &s1[i]-3;
		}



	}	






}
