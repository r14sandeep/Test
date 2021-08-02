/****i/p 10 students marks and find which student secured highest total****/
#include<stdio.h>
main()
{
int m[20][10],i,j;
float per,sum;
srand(getpid());
for(i=0;i<20;i++,printf("\n"))
{	sum=0;
	for(j=0;j<10;j++)
	{	
		m[i][j]=rand()%100;
		printf("%3d",m[i][j]);
		sum=sum+m[i][j];
	}
	printf("   sum=%f",sum);
	per=(sum/1000)*100;
	printf("   per=%f",per);
	for(j=0;j<10;j++)
	{	if(m[i][j]<40)
		{
			printf("  fail\n");
			break;
		}	
		else if(j==9)	
			{
			if(per>70)
				printf("  grade A\n");
			else if(per>60)
				printf("  grade B\n");
			else if(per>40)
				printf("  grade C\n");
			}
	}
}


}
