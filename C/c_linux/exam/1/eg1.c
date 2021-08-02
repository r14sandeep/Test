#include<stdio.h>
main()
{
	int v,i,j;
	printf("enter v");
	scanf("%d",&v);
for(i=1;i<=v;i++,printf("\n"))
{
	for(j=1;j<=(v-i);j++)
		printf(" ");
	for(j=1;j<=i;j++)
		printf("%c ",(69-j));


}
for(i=1;i<=(v-1);i++,printf("\n"))
{
	for(j=1;j<=i;j++)
		printf(" ");
	for(j=1;j<=(v-i);j++)
		printf("%c ",(68-i-j+1));

}


}
