#include<iostream>
using namespace std;
template <typename T1,typename T2>void fun(T1 a,T2 b)
{
	cout<<"T1:"<<a<<endl;
	cout<<"T2:"<<b<<endl;


}
int main()
{
	fun(12,"sandeep");
	fun("sandeep",12.345);

}
