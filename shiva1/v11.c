#include<stdio.h>
int main(){
	int x=10,y=0;
	int i=10,j=0;
	printf("x=%d y=%d\n",x,y);
	printf("i=%d j=%d\n",i,j);
	y=++x;
	j=++i;
	printf("x=%d y=%d\n",x,y);
	printf("i=%d j=%d\n",i,j);
	return 0;
}
