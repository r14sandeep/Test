/****i/p 10 students marks and find which student secured highest total****/
#include<stdio.h>
main()
{
int m[4][5],i,j,sum=0,temp=0,cnt;
srand(getpid());
for(i=0;i<4;i++,printf("\n"))
{	sum=0;
	printf("student %d:",i+1);
	for(j=1;j<=5;j++)
	{	
		m[i][j]=rand()%101;
		printf("%3d",m[i][j]);
		sum=sum+m[i][j];
	}
	printf("   total=%d",sum);
	if(sum>temp)
	{
		temp=sum;
		cnt=i+1;
	}


}
printf("student %d got highest marks\n",cnt);
}
