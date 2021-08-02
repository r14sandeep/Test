#include<stdio.h>
void input(int *,int);
void copy(int *,int *,int);
void print(int *,int );
main()
{
	int a[10],b[10];
	srand(getpid());
	input(a,10);	
	//printf("%s\n",a);
	copy(b,a,10);
	print(b,10);
	//printf("%s\n",b);
}
void input(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",p[i]=rand()%100);
	

}
void copy(int *p,int *q,int n)
{
	int i;
	for(i=0;i<n;i++)
		p[i]=q[i];


}
void print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	

}
