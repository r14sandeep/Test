// prog to check i/p is prime or not
#include<stdio.h>
main()
{
	int i,a,cnt=0;
	printf("enter a value\n");
	scanf("%d",&a);
for(i=1;i<=a;i++)
{
	if(a%i==0)
//		goto loop;
		cnt++;
}
if(cnt==2)
{
	printf("prime\n");
}
else 
{
	printf("not a prime\n");
}

//loop:  printf("not a prime\n");
//	return;

}
