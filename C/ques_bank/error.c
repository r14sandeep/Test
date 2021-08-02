#include<stdio.h>
char * fun(void)
{
  char *c = "VotaryTech";
  char *p = c;
printf("address---%p\n",c);
  c++;
  p++;
  p[5] = 65;
  return c;
}
int main()
{
 char  *t =  fun();
printf("main-address---%p\n",t);
 printf("\n%s\n", t);
}
