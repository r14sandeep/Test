#include<stdio.h>
main()
{
char c='A',c1;
int i=300,i1;
double d=34.5,d1;
char *cp=&c;
int *ip=&i;
double *dp=&d;
c1=(*cp);
i1=(*ip);
d1=(*dp);
printf("%u %u %u\n",&c,&i,&d);
printf("%u %u %u\n",cp,ip,dp);
printf("%c %d %lf\n",c1,i1,d1);
printf("%c %d %lf\n",*cp,*ip,*dp);



}
