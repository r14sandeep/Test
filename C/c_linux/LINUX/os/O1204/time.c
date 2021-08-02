#include<time.h>
#include<stdio.h>
#include<unistd.h>
main()
{
	time_t t;
	t=time(0);
	printf("%u\n",t);

}
