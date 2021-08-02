#include<stdio.h>
main()
{
int i=1,j=1;
while(i<=5)
{
	printf("%d ",i);
	j=1;
	while(j<=5){
		printf("%3d",i*j);
		j++;
		}printf("\n");
	i++;
}
}
