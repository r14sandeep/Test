#include<stdio.h>
int main()
{
	int *arr,num,index,*temp,min=0,index2=0,index3;
	printf("enter no.of elements:");
	scanf("%d",&num);
	arr=malloc(sizeof(int)*num);
	temp=malloc(sizeof(int)*num);
	printf("enter elements\n");
	for(index=0;index<num;index++)
		scanf("%d",&arr[index]);
	puts("print");
//	for(index=0;index<num;index++)
//		pirintf("%d ",arr[index]);
	for(index3=0;index3<num;index3++)
	{
		min=arr[index3];
		for(index=index3+1,index<num;index++)
		if(min>arr[index])
		{	
			temp[index2++]=arr[index];
			min=arr[index];
		}
	}
}
