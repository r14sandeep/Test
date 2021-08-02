#include<iostream>
using namespace std;
class csquare;
class crect
{
	int w,h;
	public:int area(){return (w*h);}
	void convert(csquare &);
};
class csquare
{
	private:int side;
	public:void set_side(int a){side=a;}
	friend class crect;

};
void crect::convert(csquare &a)
{
	w=a.side;h=a.side;

}
int main()
{
	csquare sqr;
	crect rect;
	sqr.set_side(4);
	rect.convert(sqr);
	cout<<rect.area();
}
