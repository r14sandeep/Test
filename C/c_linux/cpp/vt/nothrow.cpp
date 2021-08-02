#include<iostream>
int main()
{
	int *p;
	p= new (std::nothrow) int [5];
	if(p==NULL)
		std::cout<<"error"<<std::endl;


}
