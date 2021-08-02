#include<iostream>
using namespace std;
namespace first
{
	int x=1,y=2;
}
namespace second
{
	int x=3,y=4;
}
using namespace first;
//using namespace second;
int main()
{
	cout<<x<<" "<<y<<endl;
	cout<<second::x<<" "<<second::y<<endl;
}
