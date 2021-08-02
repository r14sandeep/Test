#include<iostream>
using namespace std;
class Cpoly
{
protected:
	int w,h;
public:
	void set_val(int a,int b)
	{w=a;h=b;}
};
class Coutput
{
public:
	void output(int i);

};
void Coutput::output(int i)
{cout<<i<<endl;}
class Crect:public Cpoly,public Coutput
{
public:
	int area()
	{return w*h;}
};
class Ctrgl:public Cpoly,public Coutput
{
public:
	int area()
	{return w*h/2;}
};

int main()
{
	Crect rect;
	Ctrgl trgl;
	rect.set_val(2,3);
	trgl.set_val(2,3);
	rect.output(rect.area());
	trgl.output(rect.area());

}
