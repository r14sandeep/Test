#include<stdio.h>
void main()
 {
   int a[10],i,n,min,max;
   printf("enter size of the array\n");
   scanf("%d",&n);
   printf("enter array elements\n");
   for(i=0;i<n;i++)
    { 
      scanf("%d",&a[i]);
    }
    min=max=a[0];
    for(i=1;i<n;i++)
    {
      if(a[i]<min)
      min=a[i];
      if(a[i]>max)
      max=a[i];
    }
   printf("minimum of array is : %d",min);
   printf("nmaximum of array is : %d",max);
 }   
      
