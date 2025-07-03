#include<stdio.h>
int main(){
	int n=0;
	char c='c';
	float f=34.5;
	n=sizeof(int);
	printf("%d\n",n);
	printf("%lu\n",sizeof c);
	printf("%lu\n",sizeof (float));
	printf("%lu\n",sizeof ("float"));
	printf("%u\n",sizeof ("12.34"));
	printf("%lu\n",sizeof ("c"));
	return 0;
}
