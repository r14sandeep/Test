//manage the i/p not to get repeat alphabets in the prog COUNT_OWELS.c
#include<stdio.h>
void input(int *,int );
void print(int *,int );
void countowels(int *,int );

main()
{
	int a[20],n;
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	input(a,n);
	print(a,n);
	countowels(a,n);
	
}
void input(int *p,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		p[i]=rand()%58+65;
		if(p[i]>90&&p[i]<97)
			i--;
		else 
			for(j=0;j<i;j++)
				if(p[i]==p[j])
				{	
					i--;
					break;
				}
	}
}
void print(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%c ",p[i]);
	printf("\n");

	

}
void countowels(int *p,int n)
{
	int i,cnt=0;
	for(i=0;i<n;i++)
	{
		if(p[i]==65||p[i]==69||p[i]==73||p[i]==79||p[i]==85)
				cnt++;
		else if(p[i]==97||p[i]==101||p[i]==105||p[i]==111||p[i]==117)
				cnt++;
		
	}
	printf("no.of owels is %d\n",cnt);

}
