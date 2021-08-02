#include<iostream>
using namespace std;
void  add(int a,int b)
{
	cout<<a+b;
}
float add(float a,float b)
{
	return a+b;
}
double add(double a,double b)
{
	return a+b;
}
double add(double a,int b)
{
	return a+b;
}
double add(int a,double b)
{
	return a+b;
}

main()
{
	add(10,20);
	cout<<add(12,3.2,56,7)<<endl;
	cout<<add(34,6,67,8)<<endl;
	cout<<add(34.5,60)<<endl;
	cout<<add(60,5.5)<<endl;


}
