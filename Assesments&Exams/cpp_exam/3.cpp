#include<iostream>
using namespace std;
class base
{
public:
virtual	void fun()
	{
		cout<<"base class"<<endl;

	}
	
};
class derived:public base
{
public:
	void fun()
	{
		cout<<"derived class"<<endl;
	}
	
};
int main()
{
	derived *ptr;
	ptr=new base [];
	ptr->fun();


}
