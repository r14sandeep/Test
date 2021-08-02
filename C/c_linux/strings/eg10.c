#include<stdio.h>
#include<string.h>
main()
{
char s1[20],s2[20],s3[20],s4[20];
puts("enter s1\n");
gets(s1);
puts("enter s2\n");
gets(s2);
puts("enter s3\n");
gets(s3);
/*strcpy(s4,s1);
strcpy(s4+strlen(s4)," ");
strcpy(s4+strlen(s4),s2);
strcpy(s4+strlen(s4)," ");
strcpy(s4+strlen(s4),s3);
printf("s4=%s\n",s4);
*/
strcpy(s4,s1);
strcat(s4," ");
strcat(s4,s2);
strcat(s4," ");
strcat(s4,s3);

printf("s4=%s\n",s4);


}
