#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr,size,num,i=0;
	printf("enter size:");
	scanf("%d",&size);
	ptr=malloc(size*sizeof(int));
	printf("enter num:");
	scanf("%d",&num);
	while((num!=0)&&(i<size))
	{
		ptr[i]=num;
		i++;
		if(i!=size)
		{
			printf("enter num:");
			scanf("%d",&num);
		}

	}
	int j=0;
	while(j<i)
		printf("%d ",ptr[j++]);
}
