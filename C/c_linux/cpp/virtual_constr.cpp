#include<iostream>
using namespace std;
class base
{
	int val;
public:
	base()
	{
		cout<<"base class constructor"<<endl;
	
	}
	virtual ~base()
	{
		cout<<"base class destructor"<<endl;
	}

};
class derived1:public base
{
public:
	derived1()
	{
		cout<<"derived1 class constructor"<<endl;
	}	
	~derived1()
	{
		cout<<"derived1 class destructor"<<endl;
		
	}

};

int main()
{
//	derived1 d;
	derived1 *obj1=new derived1();
	base *obj2 = obj1;	
	delete obj2;
}
