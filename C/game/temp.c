#include"header.h"
#include<termios.h>
int ch;
//pthread_t tid1;
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
   // ungetc(ch, stdin);
    return ch;
  }

//  return 0;
}

void fun1()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("i=%d\n",i);
		printf("ch=%d\n",ch);
		
//		if(ch!=1)
//			return;
		sleep(1);
	}


}
void fun2()
{
	int j;
	for(j=0;j<10;j++)
	{
		printf("j=%d\n",j);
		sleep(1);
	}
	

}

int main()
{
	fun1();
//	int ch;
	while(ch=(kbhit()))	{
//	pthread_create(&tid1,NULL,choice,NULL);
  //      pthread_join(tid1,NULL);
//	printf("after ch=%d\n",ch);
	switch(ch)
	{
		case 1:fun1();break;
		case 2:fun2();break;
	}

	}

}
