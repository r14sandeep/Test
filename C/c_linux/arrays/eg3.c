#include<stdio.h>
int main()
{
	int a[10],n,i;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
for(i=0;i<n;i++)
{
	a[i]=rand()%100;

	
printf("%d ",a[i]);

}
return 0;
}
