#include<stdio.h>
void find(int *a,int n)
{
	int i,k=0,b=0,s=0;
	for(i=0;i<n;i++)
	{
		if(((a[i]>=65)&&(a[i]<=90))||((a[i]>=97)&&(a[i]<=122)))
			k++;
		else if((a[i]>=48)&&(a[i]<=57))
			b++;
		else s++;
	}
printf("\nno.of alphabets %d\n",k);
printf("no.of numerics %d\n",b);
printf("no.of special chars %d\n",s);



}

main()
{
	int a[20],i,n;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	for(i=0;i<n;i++)
	{	a[i]=rand()%127;
	//	scanf("%d",&a[i]);
		printf("%d,%c\n",a[i],a[i]);
	}
	find(a,n);

}
