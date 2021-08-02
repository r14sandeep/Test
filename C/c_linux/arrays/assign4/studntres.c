#include<stdio.h>
void input(int *,int);
void res(int *,int);
	
main()
{
	int a[20];
	int n;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	input(a,n);
	result(a,n);


}
void input(int *p,int n)
{	
	int i;
	for(i=0;i<n;i++)
	{	p[i]=rand()%70+30;
		printf("%d ",p[i]);
	}
}
void result(int *p,int n)
{
	int d=0,f=0,s=0,t=0,cnt=0,i;
	for(i=0;i<n;i++)
	{
		if(p[i]>75)
			d++;
		else if(p[i]>70)
			f++;
		else if(p[i]>60)
			s++;
		else if(p[i]>40)
			t++;
		else
			cnt++;
	}
	printf("no.of dist students is %d\n",d);
	printf("no.of A grade students is %d\n",f);
	printf("no.of B grade students is %d\n",s);
	printf("no.of c grade students is %d\n",t);
	printf("no.of failed students is %d\n",cnt);




}
