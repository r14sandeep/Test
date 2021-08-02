#include<stdio.h>
main()
{
	int i,a,cnt=0;
	printf("enter a value");
	scanf("%d",&a);
for(i=2;i<a;i++)
{
	if(a%i==0)
		cnt++;
	//else
	//	cnt++;
}
// printf("not a prime\n");
//	return;
if(cnt>=1)
	printf("not prime\n");
	
else
	printf("prime\n");

}
