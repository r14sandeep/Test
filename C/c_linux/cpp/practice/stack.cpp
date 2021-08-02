#include<iostream>
#include<stack>
int main()
{
	std::stack <int>num;
	std::cout<<"size:"<<num.size()<<std::endl;
	num.push(1);	
	num.push(2);	
	std::cout<<"size:"<<num.size()<<std::endl;

	while(num.empty()!=true)
	{
		std::cout<<num.top()<<std::endl;
	std::cout<<"size:"<<num.size()<<std::endl;
		//std::cout<<"pop:"<<num.pop()<<std::endl;
		num.pop();
		

	}
}
