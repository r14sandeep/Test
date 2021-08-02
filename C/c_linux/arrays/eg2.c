#include<stdio.h>
main()
{
int a[10];
int n,index;
n=sizeof(a)/sizeof(a[0]);
printf("%d\n",sizeof(a[0]));
for(index=0;index<n;index++)
{
printf("enter data\n");
scanf("%d",&a[index]);

}
for(index=0;index<n;index++)
printf("%d ",a[index]);



}
