#include<iostream>
using namespace std;
template<class any1,class any2>
void display(any1 a,any2 b)
{
	cout<<a<<"\n"<<b<<endl;

}
main()
{
	display('A',123);
	display(45.6f,"deepu");
	display(67.8,56);

}
