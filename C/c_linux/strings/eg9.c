#include<stdio.h>
#include<string.h>
main()
{
char a[100]="abcdefgh",b[100]="0123456789";
strcpy(b+4,a+3);
printf("a=%s\nb=%s\n",a,b);

strcpy(a+2,b+1);

printf("a=%s\nb=%s\n",a,b);

strcpy(a+strlen(a),b+3);
printf("a=%s\nb=%s\n",a,b);

strcpy(b+strlen(b),a);
printf("a=%s\nb=%s\n",a,b);






}
