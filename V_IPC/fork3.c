#include<stdio.h>
int main()
{
	int v1;
	if(fork()==0)
	{
		system("ls");
	}
	else
		system("date");
}
