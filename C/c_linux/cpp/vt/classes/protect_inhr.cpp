#include<iostream>
using namespace std;
class base
{
protected:
//private:
	int i,j;
public:
	void set(int a,int b)
	{i=a;j=b;}
	void show()
	{cout<<"i:"<<i<<"j:"<<j<<endl;}
};
class derived:protected base
{
	int k;
public:
	void setk()
	{
		set(1,2);
		k=i+j;
	
	}
	void showall()
	{
		show();
		cout<<"k:"<<k<<endl;
	}
};
int main()
{
	derived b;
//	b.set(1,2);//inaccesable from derived cls
	b.setk();
//	b.show();//inaccesable
	b.showall();

}
