#include<iostream>
using namespace std;
class crect
{
	int w,h;
	public:void set_values(int,int);
		int area()
		{
			return (w*h);
		}
		friend crect dup(crect);
};
void crect::set_values(int a,int b)
{
	w=a;h=b;

}
crect dup(crect rectpar)
{
	crect rectres;
	rectres.w=rectpar.w*2;
	rectres.h=rectpar.h*2;
	return rectres;

};
int main()
{
	crect rect,rectb;
	rect.set_values(2,3);
	rectb=dup(rect);
	cout<<rectb.area();

}
