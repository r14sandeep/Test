#include<iostream>
using namespace std;
class xyz
{
	int x,y,z;
	public:xyz();
		xyz(int,int,int);
		void display();
		void sum();
		~xyz();
};
xyz::xyz()
     {
	cout<<"enter x,y,z:"<<endl;
	cin>>x>>y>>z;
     }
xyz::xyz(int a,int b,int c)
     {
	x=a;y=b;z=c;
     }
void xyz::display()
	{
		cout<<"x:"<<x<<endl;
		cout<<"y:"<<y<<endl;
		cout<<"z:"<<z<<endl;
	}
void xyz::sum()
	{
		cout<<"sum:"<<x+y+z<<endl;
	}
xyz::~xyz()
	{
		cout<<"destroyed"<<endl;
	}
main()
{
	xyz obj;
	obj.sum();
	obj.display();


	xyz obj1(4,5,6);
	obj1.sum();
	obj1.display();
}
