#include<iostream>
using namespace std;
class a{
	int v1;
	public:
	int v2;
	protected:
	int v3;

};
int main()
{
	class a obj;
	obj.v2=4;
	cout<<obj.v2<<endl;
//	obj.v3=5;
//	cout<<obj.v3;

}
