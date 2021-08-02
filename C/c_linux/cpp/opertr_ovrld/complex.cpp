#include<iostream>
using namespace std;
class Complex
{
	int real,imag;
	public:Complex()
		{
			real=0;imag=0;
		}
		Complex(int a,int b)
		{
			real=a;imag=b;
		}
Complex operator+(Complex &e);
Complex operator++();
//void operator++();
		void display()
		{
			cout<<real;
			if(imag>0)
				cout<<"+";
			cout<<imag<<"i"<<endl;
		}
		~Complex()
		{
			cout<<"destroyed"<<endl;
		}
	


};
Complex Complex::operator+(Complex &e)
{
	Complex temp;
	temp.real=real+e.real;
	temp.imag=imag+e.imag;

	return temp;

}
Complex Complex::operator++()
{
	real=real+1;
	imag=imag+1;
	return *this;
}
main()

{
	Complex e1(0,-45);
	cout<<"e1:"<<endl;
	e1.display();
	Complex e2(23,55);
	cout<<"e2:"<<endl;
	e2.display();
	
	Complex e3;
	e3=e1+e2;
	cout<<"e3:"<<endl;
	e3.display();

	Complex e4(10,-45);
	cout<<"E4:";
	e4.display();
	++e4;
	cout<<"e1 after pre inc:"<<endl;
	e4.display();


}
