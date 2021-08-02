#include<iostream>
using namespace std;
inline void add(int a,int b)
{
	cout<<a+b<<endl;
//	return 1;
}

main()
{
	int num1,num2,i;
	cout<<"enter num1,num2:"<<endl;
	cin>>num1>>num2;
	i=add(num1,num2);
	cout<<i<<endl;


}
