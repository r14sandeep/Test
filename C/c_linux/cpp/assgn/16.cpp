#include<iostream>
using namespace std;
main()
{
	int x=0;
	int &y=x;y=5;
	while(x<=5)
	{
		cout<<y++<<" ";
		x++;
	}
	cout<<x;

}
