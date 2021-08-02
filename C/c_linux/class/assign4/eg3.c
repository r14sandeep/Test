#include<stdio.h>
void find(int *a,int n)
{
	int i,b=0;
	for(i=0;i<n;i++)
	{
		printf("%d,%c ",a[i],a[i]);
	    if((a[i]=='A')||(a[i]=='E')||(a[i]=='I')||(a[i]=='O')||(a[i]=='U'))
		b++;
	    else if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
		b++;
	}
printf("no.of owels %d\n",b);



}


main()
{
	int a[20],i,n;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	for(i=0;i<n;i++)
	{
loop:		a[i]=65+(rand()%58);
		if((a[i]>90)&&(a[i]<97))
		{
		//	printf("spcl char,i/p again");
		//	goto loop;
			i--;
		}
		
		//printf("%d,%c ",a[i],a[i]);


	}

find(a,n);

}
