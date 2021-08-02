#include<iostream>
using namespace std;
class rectangle
{
	float area,peri,l,b;
	public:
	void set_data(float len,float bre)
	{
		l=len;b=bre;

	}
	void cal_area()
	{
//		cout<<"enter len,bredth:"<<endl;
//		cin>>l>>b;
		area=l*b;
	}
	void cal_peri()
	{
		peri=2*(l+b);
	}
	void display()
	{
		cout<<"len:"<<l<<endl;
		cout<<"bredth:"<<b<<endl;
		cout<<"area:"<<area<<endl;
		cout<<"peri:"<<peri<<endl;
	}

};
int main()
{
	rectangle obj;
	obj.set_data(5,2);
	obj.cal_area();
	obj.cal_peri();
	obj.display();
	

} 
