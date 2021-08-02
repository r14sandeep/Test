#include"header.h"
#include<math.h>
int main()
{
	int fact,res=1,num,p[2];
	pipe(p);
	printf("enter a num:");
	scanf("%d",&num);
	if(fork()==0)
	{
		read(p[0],&num,4);
		while(num)
		{
			res*=num;
			num--;
//			if(res>sizeof(int)*pow(2,10))
//				printf("high value\n");
		}

		write(p[1],&res,4);
		exit(0);
	}
	else
	{
		write(p[1],&num,4);
		sleep(1);
//		close(p[0]);
		read(p[0],&res,4);
		printf("fact value is %d\n",res);
		wait(0);
	}
	


}
