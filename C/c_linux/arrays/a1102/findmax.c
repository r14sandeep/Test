#include<stdio.h>
void input(int *,int );
void print(int *,int );
int findmax(int *,int );
main()
{
	int a[8],n,i;
	srand(getpid());
	n=sizeof(a)/sizeof(a[0]);
	input(a,n);
	print(a,n);
	i=findmax(a,n);
	printf("max is %d\n",i);
}
void input(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		p[i]=rand()%100;

}
void print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
}
int findmax(int *p,int n)
{
	int temp=-1,i;
	for(i=0;i<n;i++)
	{
		if(p[i]>temp)
			temp=p[i];
	}
//	printf("max is%d\n",temp);
	return temp;


}
