#include"header.h"
#define MAX 10
pthread_t tid1;
int size=2;
int dir=6,x=0,y=0,space=' ';
void check()
{
	if(x==(-MAX+1)||(y==(MAX-1)))
	{
		puts("game over");
		exit(0);

	}

}
void up()
{
	int i,j,k;
	for(;x<=0;x++)
	{
		system("clear");
                for(i=0;i>=x;i--)
                printf("%*c\n",y+1,space);
                for(j=0;j<size;j++)
                {
                        printf("%*c",y,space);
                        printf("*\n");
                }

//              fflush(stdout);
                check();
                sleep(1);

		
	}

}
void right()
{
	int i,j,k;
//	for(i=0;i<10;i++)
	for(y=0;y<10;y++)
	{
		system("clear");
		printf("%*c",y,space);
		for(j=0;j<size;j++)
			printf("*");
		fflush(stdout);
		//y++;
		check();
		sleep(1);
		
	}
	return;
}
void down()
{
	int i,j,k;
	for(;x>-10;x--)
	{
		system("clear");
		for(i=0;i>=x;i--)
		printf("%*c\n",y+1,space);
		for(j=0;j<size;j++)
		{
			printf("%*c",y,space);
			printf("*\n");
		}

//		fflush(stdout);
		check();
		sleep(1);
	}
}
int keyhit()
{
	int ch;
	fcntl(ch,F_SETFL,O_NONBLOCK);	
	ch=getchar();
	if(ch!=EOF)
	{
		//printf("key\n");
	
		return ch;
	}
	//	printf("key\n");
//	return 0;

}

void left()
{
	int i,j,k;
	for(;y>=0;y--)
	{
                system("clear");
		k=x;
		for(k=0;k>x;k--)
			printf("\n");
		printf("%*c",y,space);
                for(j=0;j<size;j++)
                        printf("*");
                fflush(stdout);
                //y++;
                check();
                sleep(1);


	}


}
/*void *choice(void *p)
{
	scanf("%d",&dir);
	pthread_exit(NULL);

}
*/
int main()
{
//	int ch;
	right();
//	down();
//	left();
//	up();
//	while(1)
	while((dir=keyhit()))
	{
//		pthread_create(&tid1,NULL,choice,NULL);
//		pthread_join(tid1,NULL);
		switch(dir)
		{
			case 2:down();break;
			case 4:left();break;
			case 6:right();break;
			case 8:up();break;
		
		}
	}
/*	while(1)
	{
		//printf("keyhit\n");
		ch=keyhit();
	right();
		if(ch!=0)
		switch(ch)
		{
			case 6:right();break;
			case 2:down();break;
			case 4:left();break;
			case 8:up();break;
		}
	}
*/
}
