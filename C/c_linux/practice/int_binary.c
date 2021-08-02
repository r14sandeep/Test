#include<stdio.h>
main()
{
	int n,i=8;
	printf("enter n");
	scanf("%d",&n);
	for(i=7;i>=0;i--)
	printf("%d",(n>>i)&1);
	/*loop:if(i)
		{
			printf("%d",(n>>i)&1);
			i--;
			goto loop;
		}
*/
}
