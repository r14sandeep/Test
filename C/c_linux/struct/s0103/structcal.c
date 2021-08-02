#include<stdio.h>
struct tag
{
	int a;
	char b;
	float c;
};
void input(struct tag **);
void print(struct tag*);
main()
{
	struct tag *v;
	input(&v);
	print(v);
}
void input(struct tag **v)
{
	printf("enter int,char,float:");
	scanf("%d %c%f",&((*v)->a),&((*v)->b),&((*v)->c));
	return;

}
void print(struct tag *v)
{
	printf("%d %c %f\n",v->a,v->b,v->c);

}
