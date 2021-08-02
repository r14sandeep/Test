/****strstr();*****/
#include<stdio.h>
#include<string.h>
main()
{
char s1[100],s2[100];
char *found;
printf("enter s1");
gets(s1);
printf("enter s2");
gets(s2);
/*found=strstr(s1,s2)
if(found)
	printf("found at %d\n",found-s1);
else
	printf("not found\n");
*/
found=s1;
while(found=strstr(found,s2))
{
	printf("found at %d\n",found-s1);
	found++;
}




}
