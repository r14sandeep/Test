#include<iostream>
using namespace std;
template<class type>
type add(type a,type b)
{

	return a+b;
}
main()
{
	int a,b,res;
	cout<<"enter the integer a,b"<<endl;
	cin>>a>>b;
	res=add(a,b);
	cout<<"resd:"<<res<<endl;
	float f1,f2,resf;
	cout<<"enter the float f1,f2"<<endl;
	cin>>f1>>f2;
	resf=add(f1,f2);
	cout<<"resd:"<<resf<<endl;
	double d1,d2,resd;
	cout<<"enter double d1,d2"<<endl;
	cin>>d1>>d2;
	resd=add(d1,d2);
	cout<<"resd:"<<resd<<endl;
	
}
