#include"header.h"
volatile int g_flag = 0;
void sigintHandler(int sig_num) {

    signal(SIGINT, sigintHandler);

    /* Not safe to use these functions in a signal handler */
    printf("\n Cannot be terminated using Ctrl+C \n");
    fflush(stdout);
    g_flag = 1;
}

int main (void) {
	alarm(5);
    signal(SIGALRM, sigintHandler);
//    signal(SIGTSTP, sigtstpHandler); 

    while(g_flag == 0) {}  //infinite loop.
    return g_flag;
}
