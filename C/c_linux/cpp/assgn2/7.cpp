#include<iostream>
using namespace std;
struct pixel
{
int c,s;
};
void sp(pixel p)
{
	cout<<p.c,p.s<<endl;
}
main()
{
pixel p1=(5,3);
sp(p1);
pixel p2=p1;
c.p1+=2;
sp(p2);
}
