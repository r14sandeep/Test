#include<iostream>
using namespace std;
template<class T>
class myclass
{
	T element;
public:
	myclass(T arg)
	{element=arg;}
	T increase()
	{return ++element;}

};
template<>
class myclass<char>
{
        char element;
public:
        myclass(char arg)
        {element=arg;}
        char uppercase()
        {
	if((element>='a')&&(element<='z'))
		element+='A'-'a';
	return element;
	}

};

int main()
{
	myclass<int> obj(10);
	myclass<char> obj2('g');
	cout<<"inc:"<<obj.increase()<<endl;
	cout<<"inc:"<<obj2.uppercase()<<endl;

}
