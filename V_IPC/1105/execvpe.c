#include<stdio.h>
int main(int argc,char **argv,char **env)
{
	char *cmd[]={"ls","-i",NULL};
	execvpe("ls",cmd,env);
	
}
