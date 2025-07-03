#include<stdio.h>
#include<stdlib.h>
int tables(int  n){
	int t;
	for(int i=1;i<=20;i++){
	t=n*i;
	printf("%d*%d=%d\n",n,i,t);
      }
}
int  main(){
	int n; 
	printf("enter the table to be printed:");
	scanf("%d",&n);
        tables(n);
	printf("your table is printed successfully printed\n");
	return 0;
	exit(0);
}
