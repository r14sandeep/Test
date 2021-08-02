#include<iostream>
class base
{
public:
	virtual void print()
	{std::cout<<"base print"<<std::endl;}
	void show()
	{std::cout<<"base show"<<std::endl;}
	

};
class derived:public base
{
	void print()
	{std::cout<<"derived print"<<std::endl;}
	void show()
	{std::cout<<"derived show"<<std::endl;}

};
int main()
{
	base *p;
	derived d;
	p=&d;
	p->print();
	p->show();
}
