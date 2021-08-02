/*     1
      4 16
     1 9  25 
   4  16 36  64
 1  9  25 49   81
*/
#include<stdio.h>
main()
{
int v,i,j,t;
printf("enter v");
scanf("%d",&v);
for(i=1;i<=v;i++,printf("\n"))
{
	for(j=1;j<=(v-i);j++)
		printf(" ");
	for(j=1;j<=i;j++)
	{
		if(i%2==0)
		{
			t=2*j;
			printf("%d ",t*t);	
		}	
		else
		{
			t=1*((2*j)-1);
			printf("%d ",t*t);
		
		}

	}



}
}
