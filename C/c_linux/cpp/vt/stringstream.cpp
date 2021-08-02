#include<sstream>
#include<iostream>
//using namespace std;
int main()
{
	std::string str="1234.23";
	int n;
	float f;
	std::stringstream(str)>>n>>f;
	std::cout<<"n:"<<n<<"f:"<<f<<std::endl;
	std::stringstream(str)>>f;
	std::cout<<"n:"<<n<<"f:"<<f<<std::endl;

}
