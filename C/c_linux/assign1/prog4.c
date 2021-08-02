#include<stdio.h>
main()
{
int s1,s2,s3,s4,s5;
float per,t;
printf("enter each sub marks");
scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);
t=s1+s2+s3+s4+s5;
per=t*100/250;
printf("total=%f,per=%f\n",t,per);
}
