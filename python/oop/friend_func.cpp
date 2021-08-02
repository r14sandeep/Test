#include<iostream>
using namespace std;
class rectangle
{
	float area,peri,l,b;
	public:
	rectangle()
	{
		cout<<"enter len,bredth:";
		cin>>l>>b;
	
	}
	void cal_area()
	{
		area=l*b;
	}
	void cal_peri()
	{
		peri=2*(l+b);
	}
	friend void display(rectangle &);
};
void display(rectangle &n)
{
	cout<<"area:"<<n.area<<endl;
	cout<<"area:"<<n.peri<<endl;

}
int main()
{
	rectangle obj;
	obj.cal_area();
	obj.cal_peri();
	display(obj);


}
