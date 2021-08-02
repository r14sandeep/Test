#include<iostream>

class rectangle
{
	int width,height;
public:
/*	rectangle()
	{
		width=11;height=4;
	}
*/	rectangle(int a,int b)
	{
		width=a;height=b;
	}
	int area()
	{
		return width*height;
	}


};

int main()
{
	rectangle recta(3,5);
	rectangle rectb;
	std::cout<<"area recta:"<<recta.area()<<std::endl;
	std::cout<<"area rectb:"<<rectb.area()<<std::endl;


}
