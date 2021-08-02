////ptr to base class
#include<iostream>
class poly
{
protected:
	int w,h;
public:
	void setval(int a,int b)
	{w=a;h=b;}

};
class rect:public poly
{
public:
	int area()
	{return w*h;}
};
class trgl:public poly
{
public:
	int area()
	{return w*h/2;}
};
int main()
{
	rect r;
	trgl t;
	poly *p1=&r;
	poly *p2=&t;
	p1->setval(2,3);
	p2->setval(4,6);
	std::cout<<"rect area:"<<r.area()<<std::endl;
	std::cout<<"trgl area:"<<t.area()<<std::endl;

}
