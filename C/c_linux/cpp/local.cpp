#include<iostream>
using namespace std;
int x=100;
main()
{
	int x=56;
	cout<<x<<endl;
	cout<<::x<<endl;
	{
		int x=10;
	cout<<::x<<endl;
	cout<<x<<endl;
	
	}	

}
