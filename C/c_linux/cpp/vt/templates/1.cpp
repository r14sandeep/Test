#include<iostream>
using namespace std;
template <class T>void fun(T a,T b)
{
	T res;
	res = a+b;
	cout<<"res:"<<res<<endl;
}
int main()
{
	fun(1,3);
	fun(2.4,3.64);

}
