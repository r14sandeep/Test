#include<iostream>
using namespace std;
class B;
class A
{
	public:int func1(B &b);
	private:int func2(B &b);

};
class B
{
	int _b;
	friend int A::func1(B &);
};
int A::func1(B &b){return b._b;}
int A::func2(B &b){return b._b;}
