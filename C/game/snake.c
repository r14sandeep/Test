#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>

void up(void);
void down(void);
int keyhit(void);
void right(void);
int ch=1,snake_size=3;
int x=0,y=0;
int spaces(int);
int main()
{
//	down();
//	right();
	while(keyhit())
//	while(1)
	{

		switch(ch)
		{
		//	case '8':up();break;
			case '2':down();break;
			case '6':right();break;
//			case '4':left();break;
			

		}
//	}
	}

}
/*int keyhit(void)
{
	fcntl(ch,F_SETFL,O_NONBLOCK);
	ch=getchar();
	if(ch!=EOF)
		return ch;
	else
		return 1;

}*/
void right()
{
	int t,i,j;
//	for(;x>-20;x--)
//	{
	
		t=y-3;
//		printf("%d\n",t);
		for(i=x;i<x+5;i++)
		{
			for(j=0;j>=i;j--)
				printf(" ");
			for(j=0;j<snake_size;j++)
				printf("*");
			fflush(stdout);
			system("clear");
			sleep(1);
			y++;
		}
		return;		

//	}


}
void down()
{
	int i,j,t;
//	i=x;
//	for(;i>-20;i--)
	for(i=y;i<y+5;i++)
        {
		for(j=0;j<=i;j++)
			printf("\n");
		for(j=0;j<snake_size;j++)
			printf("*\n",spaces(y));
		system("clear");
                sleep(1);
		x--;
        }
}
void up()
{
	int i,j;
	for(i=0;i<17;i++)
	{
		;

	}


}
int spaces(int sp)
{
	int i;
	for(i=0;i<sp;i++)
		printf(" ");
	return 0;
}

int keyhit(void)
{
  /*struct termios oldt, newt;
//  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(ch, F_SETFL, O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
//    ungetc(ch, stdin);
    return ch;
}

  return 1;*/
	ch=getchar();
	return ch;

}



