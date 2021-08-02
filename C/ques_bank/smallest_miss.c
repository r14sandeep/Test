#include<stdio.h>
void sort(int *p,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		if(p[j]>p[j+1])
		{
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}


}
int main()
{
	int a[5],i;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	sort(a,5);
	for(i=0;i<5;i++)
		if((a[i+1]-a[i]>1))
		{
			printf("%d\n",a[i]+1);
			break;
		}

}
