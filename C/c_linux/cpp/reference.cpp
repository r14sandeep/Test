#include<iostream>
using namespace std;
main()
{
	int x=190;
	int &ref=x;
	

	cout<<x<<endl<<ref<<endl;
	cout<<&x<<endl<<&ref<<endl;
	ref=23;
	cout<<x<<endl<<ref<<endl;
	cout<<&x<<endl<<&ref<<endl;
	int y=100;
	ref=y;  //it is not re refering,its just assigning y value to ref or x
	y=25;	
//	y=1;
	cout<<x<<y<<endl<<ref<<endl;
	cout<<&x<<endl<<&ref<<endl;
	int *p;
	int *&q=p;
	p=&x;
	cout<<*p<<endl<<*q<<endl;
	q=&y;
	cout<<*p<<endl<<*q<<x<<endl;
	//int &z=*q;
	
}
