#include<iostream>
using namespace std;
template<typename T>void display(T x,T y)
{
cout<<x<<"and"<<y<<endl;

}
template<class T>T max(T x,T y)
{
	return (x>y)?x:y;
}
int main()
{
	cout<<max(10,30)<<endl;
	//cout<<max(20.4,12.5)<<endl;
	display("deepu","qwerty");
	display(23,54);
}
