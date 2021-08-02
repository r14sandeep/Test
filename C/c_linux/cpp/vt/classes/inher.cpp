#include<iostream>
class polygon
{
protected:
	int w,h;
public:
	void setval(int a,int b)
	{w=a;h=b;}

};
class rect: public polygon
{
public:
	int area()
	{return w*h;}
};
class trgl: public polygon
{
public:
	int area()
	{return w*h/2;}
};
int main()
{
	rect obj1;
	trgl obj2;
	obj1.setval(2,3);
	obj2.setval(4,6);
//	std::cout<<"w:"<<obj1.w<<std::endl;
	std::cout<<"rect area:"<<obj1.area()<<std::endl;
	std::cout<<"rgl area:"<<obj2.area()<<std::endl;

}
