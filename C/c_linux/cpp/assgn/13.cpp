#include<iostream>
using namespace std;
main()
{
	int x=10;
	int &y=x;
	x=25;
	y=50;
	cout<<x<<" "<<--y<<endl;

}
