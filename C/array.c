#include<stdio.h>
/*int main()
{
	int arr[10],index=0;
	int num;
	printf("enter values into array:");
	scanf("%d",&num);
	while((num!=0)&&(index<10))
	{
		arr[index++]=num;
		scanf("%d",&num);
	}
	int index2,index3=0,arr2[10];
	for(index2=0;index2<index;index2++)
		if(arr[index2]>0)
			arr2[index3++]=arr[index2];
	for(index2=0;index2<index;index2++)
		if(arr[index2]<0)
			arr2[index3++]=arr[index2];
	for(index2=0;index2<index;index2++)
		printf("%d ",arr2[index2]);
		
}*/

/*int main()

{

        int arr1[5]={1,2,4,3,0};

        int arr2[5],index,num;
         for(index=0;index<5;index++)
             arr2[index]=(arr1[index]*arr1[index]);
	
        for(index=0;index<5;index++)

                printf("%d ",arr2[index]);

}*/
#include<stdio.h>
int main()
{
   int arr[8]={1,2,4,3,-2,-1,-100,-50};
   int max1,max2,low1,low2,index,size;
    size=sizeof(arr)/sizeof(arr[0]);
    max1=arr[0];
    low1=arr[0];
    max2=arr[0];
    low2=arr[0];
   for(index=1;index<size;index++)
   {	
      	if(arr[index]>max1)
              max1=arr[index];
      	if(arr[index]<low1)
	
              low1=arr[index];
      	if((arr[index]>max2)&&(arr[index]<max1))
              max2=arr[index];
      	if((arr[index]<low2)&&(arr[index]>low1))
	       low2=arr[index];
    }
/*   for(index=1;index<size;index++)
      	if((arr[index]>max2)&&(arr[index]<max1))
            max2=arr[index];
      	if((arr[index]<low2)&&(arr[index]>low1))
	       low2=arr[index];
*/
printf("%d,%d\n",max1,low1);
printf("%d,%d\n",max2,low2);

}
