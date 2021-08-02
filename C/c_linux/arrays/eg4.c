#include<stdio.h>
#include<stdlib.h>
void input(int *,int);
void print(int *,int);
void print(int *p,int n)
{
int i;
for(i=0;i<n;i++)
	printf("%d ",p[i]);
}
main()
{
int a[8];
int n,i;
srand(getpid());
n=sizeof(a)/sizeof(a[0]);
/*for(i=0;i<n;i++)
{
	a[i]=rand()%40;
	printf("%d ",a[i]);
}*/
//print(a,n);
input(a,n);
print(a,n);
}
void input(int *p,int n)
{
int i;
for(i=0;i<n;i++)
{
p[i]=rand()%40;
printf("%d,",p[i]);
}
printf("\n");
}
