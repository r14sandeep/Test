#include<stdio.h>
__fpurge();
int main()
{
//write(1,"hello",5);
printf("hello\n");
sleep(1);
close(0);
printf("enter num:");
int a;
scanf("%d",&a);
printf("%d\n",a);
//write(1,"hello",5);

}
