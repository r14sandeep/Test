#include<stdio.h>
#include<unistd.h>
main()
{
	int i=0;
	if(i==0)
		execlp("date","date",NULL);
	else
		execlp("ls","ls",NULL);
	



}
