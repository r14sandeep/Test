#include<stdio.h>
#include<stdlib.h>
void average(int **ptr,int row,int col)
{
	int index1,index2,avg=0;
	for(index1=0;index1<row;index1++)	
	{
		for(index2=0;index2<col;index2++)	
			avg+=ptr[index1][index2];
		printf("avg of row %d is %d\n",index1+1,avg);
		avg=0;
	}
}
int main()
{
	int **array,row,col,index1,index2;
	printf("enter row,col:");
	scanf("%d%d",&row,&col);
//	array=malloc(sizeof(*array)*row);
	array=calloc(row,sizeof(int)*row);
	for(index1=0;index1<row;index1++)	
	//	array[index1]=malloc(sizeof(**array)*col);
		array[index1]=calloc(1,sizeof(*array)*col);
//	printf("size=%d\n",sizeof(*array));
	printf("enter elements:");
	for(index1=0;index1<row;index1++)	
		for(index2=0;index2<col;index2++)	
			array[index1][index2]=index2;
	for(index1=0;index1<row;index1++,printf("\n"))	
		for(index2=0;index2<col;index2++)	
			printf("%d ",array[index1][index2]);
	average(array,row,col);
}
