#include<iostream>
#include<vector>
int main()
{
	int i=100;
	std::vector<int>v(10);
	std::vector<int> ::iterator p;
	p=v.begin();
	*p=300;
	p++;
	*p=20;
	p++;
	v.insert(p,33);
//	for(p=v.begin();p!=v.end();p++)
//		std::cout<<*p<<" ";
}
