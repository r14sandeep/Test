//pg to count the no.of digits of given int
#include<stdio.h>
main()
{
int v;
printf("enter v");
scanf("%d",&v);
if(v==0)
//printf("digits in %d are %d \n",v,cntdigits(v));

else
printf("digits in %d are %d \n",v,cntdigits(v)-1);


}
int cntdigits(int v)
{
 
if(v)
	return(1+cntdigits(v/10));
return 1;


}
