#include<iostream>
using namespace std;
template<typename T>void display(T x,T y);

main()
{
	display(10,3);
//	display("deepu",5);
}
template<typename T>void display(T x,T y)
{
	for(int i=1;i<=y;i++)
		cout<<x<<endl;
}
