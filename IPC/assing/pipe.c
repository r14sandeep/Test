#include"header.h"
int main()
{
	int p1[2],p2[2];
	char p1wr[100],p1rd[100],p2rd[100],p2wr[100];
	pipe(p1);
	while(1)
	{
		if(fork()==0)
		{
			puts("enter masg to parent:");
			gets(p1wr);
			write(p1[1],p1wr,strlen(p1wr)+1);
		//	close(p1[1]);
		//	dup(0);
			sleep(1);
//			read(p1[0],p1rd,100);
			printf("from parent:%s\n",p1rd);
		}
		else
		{
			read(p1[0],p2rd,100);
			printf("from child:%s\n",p2rd);
			
			puts("enter masg to child:");
			gets(p2wr);
			
			write(p2[1],p2wr,strlen(p2wr)+1);
//			sleep(1);
//			close(p2[1]);
//			dup(0);
//			read(p1[0],p2rd,100);
//			close(p1[0]);
//			dup(1);
			//printf("child:%s\n",p2rd);

		}

	}


}
