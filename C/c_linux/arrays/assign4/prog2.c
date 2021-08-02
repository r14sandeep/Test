#include<stdio.h>
void input(int *,int);
void find(int *,int);


main()
{
	int n;
	int a[20];
	srand(getpid());
	n=sizeof(a)/sizeof(a[0]);
	input(a,n);	
	find(a,n);
}
void input(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=rand()%124;
		printf("%c ",p[i]);	
	}
	

}
void find(int *p,int v)
{
	int i,a=0,n=0,s=0;
	for(i=0;i<v;i++)
	{
		if((p[i]>64&p[i]<91)||(p[i]>96&&p[i]<123))
			a++;
		else if((p[i]>47&&p[i]<58))
			n++;
		else
			s++;
	}
	printf("\nno.of alphbets is %d\n",a);
	printf("no.of numerics is %d\n",n);
	printf("no.of special chars is %d\n",s);

}



