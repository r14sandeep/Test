#include<stdio.h>
/*int main(){
	int i1=5,i2=2;
	int i3;
	float f;
	i3=i1/i2;
	f=i1/i2;
	printf("i3=%d f=%f\n",i3,f);
	i3=i1/(float)i2;
	f=i1/(float)i2;
	printf("i3=%d f=%f\n",i3,f);
	return 0;
}
int main(){
	int x=10,y=20,z=30;
	printf("%d%d%d\n",x,y,z);
	x=y=z=40;
	printf("%d%d%d\n",x,y,z);
	return 0;
}*/
int main(){
	int x=10,y=20,z=30,result=-1;
	result=x<y<z;
	printf("result=%d\n",result);
	return 0;
}
