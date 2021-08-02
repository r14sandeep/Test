#include<iostream>
using namespace std;
int main()
{
	try
	{
		throw 20;
	}
	catch(int x)
	{
		cout<<"int exception:"<<x<<endl;
	}
	catch(...)
	{
		cout<<"default exception:"<<endl;
	}
	cout<<"after excp"<<endl;
}
