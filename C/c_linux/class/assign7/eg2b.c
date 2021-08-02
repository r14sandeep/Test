/****i/p 10 students marks and find which student secured highest total****/
#include<stdio.h>
main()
{
int m[4][5],i,j,sum=0,k,temp;
srand(getpid());
for(i=0;i<4;i++,printf("\n"))
{	sum=0,temp=100;
	for(j=1;j<=5;j++)
	{	
		m[i][j]=rand()%101;
		printf("%4d",m[i][j]);
		if(temp>m[i][j])
		{
			temp=m[i][j];
			k=j;
		}
		sum=sum+m[i][j];
	}

	printf("   total=%d",sum);
	printf("\nleast scored sub is sub%d\n",k);
}
}
