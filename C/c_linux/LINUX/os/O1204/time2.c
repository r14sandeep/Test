#include<sys/timeb.h>
#include<time.h>
#include<stdio.h>
main()
{
	char datestring[20],timestring[20];
	time_t t;
	struct tm *tmptr;
	t=time(0);
	tmptr=localtime(&t)	;
	strftime(datestring,20,"%F",tmptr);
	strftime(timestring,20,"%T",tmptr);
	printf("%s %s\n",datestring,timestring);


}
