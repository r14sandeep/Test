#include<iostream>
using namespace std;
class box
{
	public:double l,h,b,vol;
	void volume()
	{
		vol=l*h*b;

	}
	void display()
	{
		cout<<"vol:"<<vol<<endl;
	}

};
int main()
{
	box a;
	box b;
	cout<<"enter l,h,b of a:";
	cin>>a.l>>a.h>>a.b;
	cout<<"enter l,h,b of b:";
	cin>>b.l>>b.h>>b.b;
	a.volume();
	a.display();
	b.volume();
	b.display();

}
