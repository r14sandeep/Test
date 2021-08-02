#include<sys/timeb.h>
#include<time.h>
#include<stdio.h>
main()
{
	char datestring[20],timestring[20];
//	time_t t;
	struct tm *tmptr;
	struct timeb t;
	//t=time(0);
	
	while(1)
	{
		ftime(&t);
		tmptr=localtime(&t.time);
		strftime(datestring,20,"%F",tmptr);
		strftime(datestring,20,"%T",tmptr);
		printf("%s %s %d\n",datestring,timestring,t.millitm);
		//sleep(1);
		usleep(100000);
		system("clear");
	}

}
