#include<stdio.h>

void fun(int *arr,int size,char *ptr)
{
	int i,j,ind;
	char str[10],temp;
	for(i=0;i<size;i++)
	{
		ind=arr[i];
		printf("%c",ptr[ind]);
		temp=ptr[ind];
		for(j=ind-1;j>=0;j--)
		{
			ptr[j+1]=ptr[j];
		}
		ptr[0]=temp;

	}
	printf("\n");

}

int main()
{
	//int arr[]={6, 5, 0, 10, 18, 8, 15, 18,6, 6, 0, 6, 6},i,j,size;
	int arr[]={15, 1, 14, 1, 14, 1},i,j,size;
	char str[30]="abcdefghijklmnopqrstuvwxyz";
	size=sizeof(arr)/sizeof(arr[0]);
	fun(arr,size,str);
	puts(str);	

}
