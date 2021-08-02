#include<iostream>
using namespace std;
int x=10;
int main()
{
	int x=1;
	cout<<"local:"<<x<<endl;
	cout<<"global:"<<::x<<endl;
	{
		int x=-2;
	cout<<"local:"<<x<<endl;
	cout<<"global:"<<::x<<endl;
		
	}

}
