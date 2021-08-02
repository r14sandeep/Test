#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
	srand(static_cast <unsigned> (time(0)));
	float r = -1+static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(1+1));
	std::cout<<r<<std::endl;
}
