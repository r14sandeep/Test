#include<stdio.h>
int main(){
/*	int a=10,b=11;
	printf("%d\n",++a>b--);
	printf("a=%d b=%d\n",a,b);
	a=10;b=11;
	printf("%d\n",a++<--b);
	return 0;
}
int a=5,b=0,c=-3,d=-1;
printf("%d %d %d %d\n",a,b,c,d);
d=++a||++b||++c;
printf("%d %d %d %d\n",a,b,c,d);
a=5,b=0,c=-3,d=-1;
d=b++&&c++&&a++;
printf("%d %d %d %d\n",a,b,c,d);
a=5,b=0,c=-3,d=-1;
d=++b&&++c&&++a;
printf("%d %d %d %d\n",a,b,c,d);
}*/
int a,b,c;
int result;
printf("enter 3 intergers:");
scanf("%d%d%d",&a,&b,&c);
result=(a<0)&&(b<0)&&(c<0);
printf("result=%d\n",result);
result=(a>b)&&(b>c);
printf("result=%d\n",result);
return 0;
}
