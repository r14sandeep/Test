#include<stdio.h>
main()
{
int a[10]={11,22,33,44,55},n,index;
n=sizeof(a)/sizeof(a[0]);
printf("size %d\n",n);
for(index=0;index<n;index++)
printf("a[%d]=%d ",index,a[index]);



}
