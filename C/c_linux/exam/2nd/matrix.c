#include<stdio.h>
//int res[3][3];
void *sub(int (*a)[2],int (*b)[2])
{
	int i,j,(*p)[2],res[2][2];
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			res[i][j]=a[i][j]-b[i][j];
	p=res;
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<2;j++)
		printf("%d\n",p[i][j]);
	return p;


}



main()
{
	int a[2][2],b[2][2],i,j,(*p)[2];
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			printf("enter a");
			scanf("%d",&a[i][j]);
		}
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			printf("enter b");
                        scanf("%d",&b[i][j]);

		}


	p=sub(a,b);
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<2;j++)
		printf("%d ",p[i][j]);
	

}
