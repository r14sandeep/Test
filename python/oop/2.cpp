#include<iostream>
using namespace std;
class base
{
//	public:
	int v1;
	int v2;

};
class derived:public base
{
	public:
	void display()
	{
	base.v1=0;base.v2=33;	
	cout<<base.v1<<base.v2<<endl;
	}

};
int main()
{
	derived obj;
	obj.display();

}
