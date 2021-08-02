#include<iostream>
using namespace std;
class Complex
{
	int real,img;	
	public:void setdata(int a,int b)
		{
			real=a;img=b;
		}
		Complex add(Complex &e)
		{
			Complex temp;
			temp.real=real+e.real;
			temp.img=img+e.img;
			return temp;

		}
		void display()
		{
			cout<<real;
			if(img>0)
				cout<<"+";
			cout<<img<<"i"<<endl;
		}
};
main()
{
	Complex e1;
	int a,b;
	cout<<"enter a,b"<<endl;
	cin>>a>>b;
	e1.setdata(a,b);
	cout<<"e1:";
	e1.display();
	Complex e2;
	e2=e1.add(e1);
	e2.display();
}
