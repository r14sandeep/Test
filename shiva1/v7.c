#include<stdio.h>
int main(){
	short int s1=0,s2=0;
	unsigned short int u1=0,u2=0;
	printf("s1=%hd s2=%hd\n",s1,s2);
	printf("u1=%hu u2=%hu\n",u1,u2);
	u2=u1-1;
	s2=s1-1;
	printf("s1=%hd s2=%hd\n",s1,s2);
	printf("u1=%hu u2=%hu\n",u1,u2);
	return 0;
}
