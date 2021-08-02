#include<iostream>
using namespace std;
class deep
{
	int v1,v2;
public:
	deep()
	{
		v1=12;v2=10;
	}
	deep(deep &s)
	{
		v1=s.v1;
		v2=s.v2;
	}
	void setdata(int a,int b)
	{
		v1=a;v2=b;
	}
	void getdata()
	{
		cout<<"v1:"<<v1<<endl;
		cout<<"v2:"<<v2<<endl;
	}

};

int main()
{
	deep obj1;
	cout<<"obj1 output"<<endl;
	obj1.getdata();
	deep obj2=obj1;
//	obj2=obj1;
	obj2.getdata();
	obj2.setdata(1,2);
	cout<<"obj1 output after data changed(deep copy)"<<endl;
	obj1.getdata();
	obj2.getdata();

	

}
