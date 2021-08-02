#include<iostream>
using namespace std;
class abc
{
	const int x;
	int y;
	public:abc() :x(10)
		{
			cout<<"enter y"<<endl;
			cin>>y;
		}
	abc(int a,int b) :x(a)
	{
		y=b;
	}
	void display()
	{
		cout<<"x:"<<x<<endl;
		cout<<"y:"<<y<<endl;
		
	}
};
int main()
{
	abc obj;
	obj.display();
	abc obj1(20,60);
	obj1.display();

}
