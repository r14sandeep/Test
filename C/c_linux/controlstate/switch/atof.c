#include<stdio.h>
#include<math.h>
float myatoi(char *);
main()
{
	char a[10];
	float i;
	printf("enter a:");
	scanf("%s",a);
	i=myatoi(a);	
	printf("%f\n",i);
}
float myatoi(char *a)
{
	float i,j=0;
	int cnt=0;
	while(*a)	
	{
		i=(*a)-48;
		j=j*10+i;
		a++;
		if(*a=='.')
			break;
	}
	a++;
	while(*a)
	{
		i=(*a)-48;
		j=j*10+i;
		cnt++;
		a++;
	}
	j=j*pow(10,-cnt);
//	printf("%f\n",j);
	return j;

}
