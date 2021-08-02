#include<stdio.h>
struct tag
{
	int a;
	char b;
	float c;
	

};
void print(struct tag *);
void input(struct tag *);
main()
{
	struct tag v;
	print(&v);
	input(&v);
	print(&v);


}
void print(struct tag *p)
{
	printf("%d %c %f\n",p->a,p->b,(*p).c);


}
void input(struct tag *p)
{
	printf("enter char");	
	scanf("%c",&(*p).b);
	printf("enter int");
	scanf("%d",&p->a);
	printf("enter real:");
	scanf("%f",&p->c);
	
}
