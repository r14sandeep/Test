#include<stdio.h>
int main(){
	int x=10,y;
	y=x>>3;
	printf("y=%d\n",y);
	printf("%d\n",1>>5);
        printf("%d\n",1>>10);
	printf("%d\n",1>>20);
	printf("%d\n",1>>30);
	printf("%d",1>>31);
	return 0;
}
