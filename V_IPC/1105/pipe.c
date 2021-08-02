#include"header.h"
int main()
{
	int arr[6]={1,-3,4,2,-5,-1},p1[2],p2[2];
	pipe(p1);
	pipe(p2);
	int val,sum;
	val=fork();
	if(val)
	{
		write(p1[1],&arr,sizeof(arr));
		printf("parent writeing done,waiting for child1 to exit\n");
		sleep(4);
		printf("parent reading\n");
		read(p1[0],&sum,4);
		printf("sum=%d\n",sum);
		waitpid(val);
		printf("parent exiting\n");
	}
	else
	{
		int arr_ch[6],i,pid;

		read(p1[0],&arr_ch,sizeof(arr));
		printf("in child1\n");
		for(i=0;i<6;i++)
		{
			puts("child1 writing");
//			close(1);
//			dup(p2[1]);
			if(arr_ch[i]>=0)
			write(p2[1],&arr_ch[i],4);
//			printf("%d",arr_ch[i]);
//			sleep(1);

		}
//		write(p2[1],&arr_ch[i],4);
		pid=fork();
		if(pid==0)
		{
			printf("in child2\n");
			int sum=0,v,j;
			
			for(j=0;j<3;j++)
			{	
				
//				while(read(p2[0],&v,4)){
				read(p2[0],&v,4);
				sum+=v;
				printf("%d\n",sum);
			}
			puts("child2 writing");
			write(p1[1],&sum,4);
			puts("child2 exiting");
			exit(0);
		}
		
		waitpid(pid);
		printf("child1 exiting\n");
//		sleep(4);		
		exit(0);

	}
	
}
