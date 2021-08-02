#include<iostream>
class rectangle
{
	int x,y;
public:
	void setval(int a,int b)
	{
		x=a;y=b;
	}
	int area()
	{
		return x*y;
	}

};

int main()
{
	rectangle rect1,*b,*c,*d,obj[2];
	rect1.setval(2,4);
	std::cout<<"react1:"<<rect1.area()<<std::endl;
	b=new rectangle;
	b->setval(4,5);
	std::cout<<"b:"<<b->area()<<std::endl;
	obj[0].setval(1,2);
	std::cout<<"b:"<<obj[0].area()<<std::endl;
	obj[1].setval(5,8);
	std::cout<<"b:"<<obj[1].area()<<std::endl;
	


}
