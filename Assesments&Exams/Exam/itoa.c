#include<string.h>
#include<stdio.h>
	char a[10];
char* myitoa(int n)
{
	int i,j,k,t;
	
	for(i=0;i<10;i++)
	{	
		t=n%10;
		a[i]=t+48;
		n=n/10;
		if(n==0)
		{
			a[i+1]='\0';
			break;
		}
	}
	k=strlen(a);
	for(i=0,j=k-1;i<j;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	puts(a);
	return a;
}
int rightrotate(int num,int rot)
{
	char str[10],temp;
	int len,ind,n=0;
	str=myitoa(num);
	len=strlen(str);
	while(n<rot)
	{
		temp=str[len-1];
		for(ind=len-1;ind>0;ind--)
		{
			str[ind]=str[ind-1];	
		}
		n++;
	}
	puts(str);
	num=atoi(str);
	return num;
}
int main()
{
	int n,res;	
	char *p=NULL;
	printf("enter n:");
	scanf("%d",&n);
	p=myitoa(n);
	puts(p);
	res=rightrotate(1234,2);
	printf("res:%d\n",res);
	//printf("%s\n",p);
}
