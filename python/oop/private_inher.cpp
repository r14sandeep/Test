#include<iostream>
using namespace std;
class base
{
	int v1=4,v2=1;
	protected:
		int num=19;
	public:
		void display()
		{
			printf("in base class\n");
		}
};
class derived:private base
{
	

};
int main()
{
	


}
