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
void operator=(Complex &);
void operator+=(Complex &);
void operator-=(Complex &);
//void operator+=(Complex &e3);
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
void Complex::operator=(Complex &e)
{
	real=e.real;
	imag=e.imag;


}
void Complex::operator+=(Complex &e1)
{
	real=real+e1.real;
	imag=imag+e1.imag;
}
void Complex::operator-=(Complex &e2)
{
	real=real-e2.real;
	imag=imag-e2.imag;

}
main()

{
	Complex e1(2,-4),e3;
	cout<<"e1:"<<endl;
	e1.display();
	Complex e2(3,8);
	cout<<"e2:"<<endl;
	e2.display();
	
	e3=e1;
	cout<<"e3:"<<endl;
	e3.display();
	e3+=e1;
	cout<<"e3+e1=";
	e3.display();
	e3-=e2;
	cout<<"e3-e2=";
	e3.display();
	

}
