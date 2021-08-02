#include<iostream>
#include<vector>
int main()
{
	int i;
	std::vector<int>v(10);
	for(i=0;i<10;i++)
		v[i]=i;
	for(i=10;i<20;i++)
		v.push_back(i);
	for(i=0;i<20;i++)
		std::cout<<v[i]<<std::endl;
	std::cout<<v.size()<<std::endl;

}
