#include<iostream>
class base
{
	int *ptr;
public:
	base()
	{
		std::cout<<"default"<<std::endl;
		ptr=NULL;
	}	
	base(int v)
	{
		ptr=new int;	
		*ptr=v;
	}
	base(base &b)
	{
		ptr=new int;
		*ptr=*b.ptr;
		std::cout<<"addr:"<<ptr<<std::endl;
	}
	void set(int v)
	{*ptr=v;}
	int get()
	{return *ptr;}
};

int main()
{
	base obj1(3),obj2=obj1;
	std::cout<<obj1.get()<<std::endl;
	std::cout<<obj2.get()<<std::endl;

	obj1.set(44);
	std::cout<<obj1.get()<<std::endl;
	std::cout<<obj2.get()<<std::endl;
	

}


