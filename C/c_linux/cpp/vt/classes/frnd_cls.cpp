#include<iostream>
class Csquare;
class Crect
{
	int w,h;
public:
	int area()
	{return w*h;}
	void convert(Csquare a);

};
class Csquare
{
	int side;
public:
	void set_side(int a)
	{side=a;}
	friend class Crect;

};
void Crect::convert(Csquare a)
{
	w=a.side;
	h=a.side;
}

int main()
{
	Csquare sqr;
	Crect rect;
	sqr.set_side(3);
	rect.convert(sqr);
	std::cout<<rect.area()<<std::endl;

}

