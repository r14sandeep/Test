#include<stdio.h>
void find(int *a,int n)
{
	int i,b=0;
for(i=0;i<n;i++)
{
	if((a[i]=='A')||(a[i]=='E')||(a[i]=='I')||(a[i]=='O')||(a[i]=='U'))
		b++;
	else if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))		b++;	


}
printf("no.of owels %d\n",b);


}
main()
{
	int i,a[20],j,n;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	for(i=0;i<n;i++)
	{
loop:		a[i]=65+(rand()%58);
		if((a[i]>90)&&(a[i]<97))
		{
			printf("spcl char,i/p again\n");
			goto loop;
		}
		else
		{	
			for(j=0;j<i;j++)
			{//printf("a[%d]=%c,",i,a[i]);
				if(a[i]==a[j])
				{
					printf("repeated data,i/p again\n");
					goto loop;		

				}

		}}

	printf("a[%d]=%c,",i,a[i]);

	}

find(a,n);

}
