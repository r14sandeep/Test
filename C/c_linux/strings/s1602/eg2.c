#include<stdio.h>
#include<string.h>
main()
{
	char str[100];
	char *ptr,*found;
	puts("enter string:");
	fgets(str,100,stdin);
	//gets(str);
	printf("%d\n",strlen(str));
	str[strlen(str)-1]='\0';
	//printf("%d %c\n",strlen(str)-1,str[6]);
	ptr=str;
	while(*ptr)
	{
		if(found=strchr(ptr+1,*ptr))
			memmove(found,found+1,strlen(found+1)+1);
		else
		ptr++;
	}
	printf("%s....\n",str);

}
