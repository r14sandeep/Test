#include<stdio.h>
int main()
{
	int arr[10]={1,2,9,1,6,4,9,8,0,3};
	int index1,index2,size,ind;
	size=sizeof(arr)/sizeof(arr[0]);
	for(index1=0;index1<size;index1++)
		printf("%d ",arr[index1]);
	printf("\n");
	for(index1=0;index1<size;index1++)
	{
		for(index2=index1+1;index2<size;index2++)
			if(arr[index1]==arr[index2])
			{
				for(ind=index2;ind<size-1;ind++)
					arr[ind]=arr[ind+1];
				size=size-1;
				index2--;
			}
	}
	for(index1=0;index1<size;index1++)
		printf("%d ",arr[index1]);

}
