#include<stdio.h>
int main(int argc,char **argv,char **env)
{
	char *cmd[]={"./sum",NULL};
	execve("./sum",cmd,env);

}
