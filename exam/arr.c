/*print the two elements of arr which are equals to whole sum of arr exceping these two values*/
/*in below arr 1+3=4 which is = 0+2+2*/
#include<stdio.h>
int main()
{
	int a[10]={0,1,2,3,2};
	int size,i,j,k,sum1=0,sum2=0;
	for(i=0;i<5;i++)
	{
		sum1=0;
		for(j=0;j<5;j++)
		{
			sum2=0;
			sum1=a[i]+a[j];
			for(k=0;k<5;k++)
			{
				if((k!=i)&&(k!=j))
					sum2+=a[k];
			}
			if(sum1==sum2)
			{
				printf("%d,%d=%d\n",a[i],a[j],sum2);
				break;
			}

		}
	}
	

}
