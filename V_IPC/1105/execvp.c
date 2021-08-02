#include<stdio.h>
int main(int argc,char **argv,char **env)
{
	int val;
	char *cmd[]={"ls","-i",NULL};
	execvp("ls",cmd);

}
