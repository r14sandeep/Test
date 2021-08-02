#include<stdio.h>
int res[2][2];
void *sub(int (*a)[2],int (*b)[2])
{
	int i,j;
	int (*p)[2]=0;//res[2][2];
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			res[i][j]=a[i][j]+b[i][j];
	//p=res;
//		for(i=0;i<2;i++)
//			for(j=0;j<2;j++)
//		printf("%d\n",p[i][j]);
	printf("Return Add.->.....%d\n",p);
	return res;


}
main()
{
	int a[2][2],b[2][2],i,j,(*p)[2]=0;
	srand(getpid());
//	int res[2][2]=0;
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<2;j++)
		{
			//printf("enter a");
			//scanf("%d",&a[i][j]);
			printf("%d ",a[i][j]=rand()%50);
		}
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<2;j++)
		{
		//	printf("enter b");
                  //      scanf("%d",&b[i][j]);
			printf("%d ",b[i][j]=rand()%50);
			
		}


	p=sub(a,b);
//	res=p;
//	printf("Collected Add->>%d\n",q);
//	p++;
	//printf("After Add->>%d\n",*q);
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<2;j++)
			printf("%d ",p[i][j]);
			//for(i=0;i<2;i++)
			//printf("%d\n",**p);
}
