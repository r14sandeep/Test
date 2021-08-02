#include<iostream>
using namespace std;
class Complex
{
	private:float real,imag;
	public:Complex(){real=imag=0;}
	Complex(float inreal)
	{
		real=inreal;
		imag=0;
	}
	void getdata()
	{
		cout<<"enter real,imag:";
		cin>>real>>imag;
	}
	friend Complex operator+(Complex c1,Complex c2);
	friend istream & operator>>(istream &in,Complex &c);
	friend ostream & operator<<(ostream &out,Complex &c);
};
istream &operator>>(istream &in,Complex &c)
{
	cout<<"real:";
	in>>c.real;
	cout<<"imag:";
	in>>c.imag;
	return in;

}
ostream & operator<<(ostream &out,Complex &c)
{
	out<<c.real;
	if(c.imag>0)
	out<<c.imag<<"+i";
	else
	out<<c.imag<<"i";
	return out;

}
main()
{
	Complex c1,c2,c3,c4;
	cout<<"enter c1";
	cin>>c1;

	cout<<"enter c2";
	cin>>c2;
	cout<<"c1:";
	cout<<c1<<endl;
	


}
