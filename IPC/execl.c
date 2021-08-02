#include<unistd.h>
int main()
{
	system("pwd");
	execl("/bin/ls","ls",NULL);
	printf("end\n");
	exit(0);
}
