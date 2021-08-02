#include"header.h"
int main(int argc,char **argv,char **env)
{
	int val;
	char *cmd[]={"./sum","1","4","5",NULL};
//	if(fork()==0)
//	execl("./sum 3 2 5","./sum 3 2 5",NULL);
//	execl("./sum","./sum","2","4","5",NULL);
	execle("./sum","./sum","2","4","5",NULL,env);
//	execv("./sum",cmd);	
}
