#include<iostream>
class crect
{
	int w,h;
public:
	void setval(int a,int b)
	{
		w=a;h=b;
		
	}
	int area()
	{
		return w*h;
	}

	friend crect dup(crect);

};
crect dup(crect a)
{
	crect temp;
	temp.w=a.w*2;
	temp.h=a.h*2;
	return temp;
}
int main()
{
	crect obj1,obj2;
	obj1.setval(2,3);
	obj2=dup(obj1);
	std::cout<<"area:"<<obj2.area()<<std::endl;
}
