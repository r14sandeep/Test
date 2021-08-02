#include<stdio.h>
int find(int v,int *pmin,int *pmax)
{
	int tempmin=10,tempmax=-1;
	int digit;
while(v)
{
	digit=v%10;
	if(digit<tempmin)
		tempmin=digit;
	if(digit>tempmax)
		tempmax=digit;
	v=v/10;


}
*pmin=tempmin;
*pmax=tempmax;
return 0;

}
main()
{
	int v,min,max;
	printf("enter v");
	scanf("%d",&v);
	find(v,&min,&max);
	printf("min=%d max=%d\n",min,max);



}
