#include<iostream>
using namespace std;
void fun(int x)throw (int) //means throws int excp
//void fun(int x)throw () //means throws no excp
//void fun(int x); //means throws all excp
{
	throw x*2;
	//throw "abc";

}
int main()
{
	try
	{
		cout<<"in try"<<endl;
		fun(3);
	}
	catch(int x)
	{
		cout<<x<<endl;
	}
}
