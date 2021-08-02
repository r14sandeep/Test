#include<stdio.h>
#include<math.h>
float myatof(char *p)
{
	int i,cnt=0,j,temp1=0;
	float res;
	for(i=0;p[i];i++)
	{
		if(p[i]=='.')
			break;
		temp1=temp1*10+p[i]-48;
		
	}
	for(j=i+1;p[j];j++)
	{
	temp1=temp1*10+p[j]-48;
	cnt++;
	}
	res=temp1*pow(10,-cnt);
	return res;

}
main()
{
	char a[100];
	float f;
	puts("enter a");
	gets(a);
	f=myatof(a);
	printf("%f\n",f);


}
