#include<iostream>
using namespace std;
class adder
{
	//int total;
	public:adder(int i=0)
	{
		total=i;
	}
	void addnum(int num)
	{
		total+=num;
	}
	int gettot()
	{
		return total;
	}
	private:int total;

};
main()
{
	adder a;
	a.addnum(10);
	a.addnum(20);
	a.addnum(30);
	cout<<"total:"<<a.gettot()<<endl;
}
