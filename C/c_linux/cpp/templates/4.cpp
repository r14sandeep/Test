#include<iostream>
using namespace std;
template<typename T>void abc(T x)
{
	cout<<"inside generic fn"<<endl;
	cout<<"x="<<x<<endl;
}
void abc(int x)
{
	cout<<"inside normal fn"<<endl;
	cout<<"x="<<x<<endl;
}
main()
{
	abc(23.56);
	abc(25);
	abc("deepu");

}
