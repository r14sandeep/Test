#include<iostream>
using namespace std;
template <typename T>
class rect
{
	T a,b;
public:
	rect(T v1,T v2)
	{a=v1;b=v2;}
	T getmax();
};
template <typename T>T rect<T>::getmax()
{
	T res;
	res=(a>b)?a:b;
	return res;
}
int main()
{
	//rect<int> obj(52.3,45.45);
	rect<int> obj('a','b');
	rect<char> obj2('a','b');
	//rect<string> obj("a","b");
	cout<<"max:"<<obj.getmax()<<endl;
	cout<<"max:"<<obj2.getmax()<<endl;
}
