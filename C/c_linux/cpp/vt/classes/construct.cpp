#include<iostream>
class Rect
{
	int x,y;
public:
	Rect(int ,int);	
	int area()
	{
		return x*y;
	}
};
Rect::Rect(int a,int b)
{
	x=a;y=b;

}
int main()
{
	Rect obj(5,8);
	std::cout<<"area:"<<obj.area()<<std::endl;
	

}
