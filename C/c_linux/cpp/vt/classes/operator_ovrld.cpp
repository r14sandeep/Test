#include<iostream>

class Cvector
{
public:
	int x,y;
	Cvector(){}
	Cvector(int a,int b)
	{
		x=a;y=b;
	}
	Cvector operator + (Cvector);

};

Cvector Cvector::operator + (Cvector val)
{
	Cvector temp;
	std::cout<<"x:"<<val.x;
	temp.x=x+val.x;
	temp.y=y+val.y;
	return temp;
	//return *this;
}

int main()
{
	Cvector val1(2,3),val2(1,2),val4;
	val4=val1+val2;
	//std::cout<<"val3:"<<val3.x<<val3.y<<std::endl;
	std::cout<<"val4:"<<val4.x<<val4.y<<std::endl;


}
