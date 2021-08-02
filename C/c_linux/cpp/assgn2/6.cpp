#include<iostream>
using namespace std;
struct my
{
int l,b,h;
};
void dim(my m)
{
cout<<"l:"<<m.l<<"b:"<<m.b<<"h:"<<m.h<<endl;

}
main()
{
	my b1={10,15,5},b2,b3;
	++b1.h;
	dim(b1);
	b3=b1;
	++b3.l;
	b3.b++;
	dim(b3);
	b2=b3;
	b2.h+=5;
	b2.l--;
	dim(b2);

}
