#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T,N,*arr,i,j,sum=0;
	printf("enter test cases:");
	scanf("%d",&T);
	while(T>0)
	{
		printf("enter array size:");
		scanf("%d",&N);
		arr=malloc(sizeof(int)*N);
		if(arr==NULL)
		{
			puts("memory not allocated");
			return 1;
		}
		printf("enter elements into array:");
		for(i=0;i<N;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<N;i++)
			for(j=i+1;j<N;j++)
			{
				sum+=arr[i]^arr[j];
			}
		printf("sum is %d\n",sum);
		free(arr);
		sum=0;
		T--;
	}

}
