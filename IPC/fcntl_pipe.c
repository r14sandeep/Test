#include"header.h"
int main()
{
	int p[2],cnt=0;
	char ch;
	pipe(p);
//	fcntl(p[1],F_SETFL,O_NONBLOCK);//if we dnt use it pipe will block writing/ when it full
//		if(fork())
		while(1)
		{
			if(write(p[1],"a",1)==1)
				cnt++;
			else break;
			printf("%d\n",cnt);
		}
		
//		else
		//	printf("reading\n");
			//read(p[0],&ch,1);
	printf("%c\n",ch);
}
