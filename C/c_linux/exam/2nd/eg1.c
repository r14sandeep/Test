#include<stdio.h>
//int res[3][3];
int (*sub(int (*a)[2],int (*b)[2]))[2]
{
	int i,j;
	static int (*p)[2]=0,res[2][2];
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			res[i][j]=a[i][j]-b[i][j];
	p=res;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
		printf("%d\n",p[i][j]);
	printf("Return Add.->.....%d\n",p);
	return p;


}
main()
{
	int a[2][2],b[2][2],i,j,(*p)[2]=0;
//	int res[2][2]=0;
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
