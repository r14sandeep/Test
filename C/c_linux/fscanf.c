#include<stdio.h>
struct d
{
	char b[10];
};
int main()
{
	struct d *p;
	FILE *fp;
	char a[20],b[10],c[10],d;
//	float b;
	fp=fopen("test.txt","r");
//	fscanf(fp,"%s%f",a,&b);
	fgets(a,20,fp);
//	puts(a);
//	sscanf(a,"%s",p->b);
	sscanf(a,"%s%s",b,c);
	puts(b);
	puts(c);
	rewind(fp);
	fscanf(fp,"%s%c",b,&d);
	puts(b);
	printf("%c\n",d);
//	fscanf(fp,"%s",p->b);
//	printf("%f\n",b);
//	puts(p->b);	
}
