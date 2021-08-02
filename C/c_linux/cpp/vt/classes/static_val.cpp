#include<iostream>

class rect
{
public:
	static int n;
	rect()
	{
		std::cout<<"constr"<<std::endl;
		n++;
	}
	~rect(){n--;}

};
int rect::n=0;
int main()
{
	rect a[3];
	std::cout<<"n:"<<a[0].n<<std::endl;
	std::cout<<"n:"<<a[1].n<<std::endl;
	std::cout<<"n:"<<a[2].n<<std::endl;

}
