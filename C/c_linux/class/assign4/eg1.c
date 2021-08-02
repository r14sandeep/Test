#include<stdio.h>
#include<stdlib.h>
//void find(int,int);
void find(int *p,int n)
{
	int i,b=0,c=0,d=0,e=0,f=0;
	for(i=0;i<n;i++)
	{
		if(p[i]>=75)
			b++;
		else if(p[i]>=70)
			c++;
		else if(p[i]>=65)
			d++;
		else if(p[i]>=55)
			e++;
		else
			f++;
	}	

	printf("\nno.of dist students %d\n",b);
	printf("no.of 1st class students %d\n",c);
	printf("no.of 2nd class students %d\n",d);
	printf("no.of 3rd class students %d\n",e);
	printf("no.of failed students %d\n",f);

}
main()
{
	int a[20],i,n;
        srand(getpid());
	printf("%d,%d\n",sizeof(a[0]),sizeof(a));
        n=sizeof(a)/sizeof(a[0]);
        for(i=0;i<n;i++)
                printf("a[%d]=%d ",i,a[i]=rand()%100);
        find(a,n);


}
