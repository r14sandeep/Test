#include<stdio.h>
int f1(int);
int f2(int);
main()
{
	int v=1;
	printf("in main:v=%d at %u\n",v,&v);
	f1(v+5);
	printf("in main:v=%d at %u\n",v,&v);
}
int f1(int v)
{
	printf("in f1:v=%d at %u\n",v,&v);
	f2(v++);
	printf("in f1:v=%d at %u\n",v,&v);

}
int f2(int v)
{
	printf("in f2:v=%d at %u\n",v,&v);
	v+=10;
	printf("in f2:v=%d at %u\n",v,&v);



}
