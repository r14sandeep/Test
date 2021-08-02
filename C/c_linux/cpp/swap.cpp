#include<iostream>
using namespace std;
void swap_val(int a,int b);
void swap_val(int *a,int *b);
main()
{
	int num1,num2;
	cout<<"enter num1,num2:";
	cin>>num1>>num2;
	cout<<"b4 swaping:"<<num1<<num2<<endl;
	swap_val(num1,num2);
	cout<<"after swap num1:"<<num1<<"num2:"<<num2<<endl;
	//swap_val(&num1,&num2);
	swap_val(num1,num2);
	//swap_val(&num1,&num2);
	
	cout<<"after swap num1:"<<num1<<"num2:"<<num2<<endl;
}
void swap_val(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void swap_val(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swap_val(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;

}

