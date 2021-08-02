#include<iostream>
class parent
{
public:
	int p;

};

class child:public parent
{
public:
	int c;

};


int main()
{
	child obj;
	obj.p=1;obj.c=2;
	std::cout<<obj.c<<obj.p<<std::endl;	


}
