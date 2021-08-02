#include<stdio.h>
void f1(void)
{
	printf("in f1\n");
	while(1);

}
void f2(void)
{
	printf("in f2\n");
	while(1);
}
main()
{
//	f1();
//	f2();
	if(fork()==0)
		f1();
	else
		f2();
}
