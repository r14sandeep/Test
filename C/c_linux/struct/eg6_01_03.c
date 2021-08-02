#include<stdio.h>
struct tag
{
	int a;
	char b;
	float c;
	

};
void print(struct tag);
struct tag input(struct tag);
main()
{
	struct tag v;
	print(v);
	v=input(v);
	print(v);


}
void print(struct tag var)
{
	printf("%d %c %f\n",var.a,var.b,var.c);


}
struct tag input(struct tag v)
{
	printf("enter char");	
	scanf("%c",&v.b);
	printf("enter int");
	scanf("%d",&v.a);
	printf("enter real:");
	scanf("%f",&v.c);
	return v;
}
