#include<iostream>
using namespace std;
class rectangle
{
	float area,peri,l,b;
	private:void setdata()
//	public:rectangle()
		{
			cout<<"enter len,bre:"<<endl;
			cin>>l>>b;
		}
	
		void cal_area()
//		void rectangle()
		{
		//	cout<<"enter len,bre:"<<endl;
		//	cin>>l>>b;
			area=l*b;
		}
		void cal_peri()
//		void rectangle()
		{
			peri=2*(l+b);
		}
	public:	void display()
		{
			setdata();
			cout<<"length:"<<l<<endl;
			cout<<"bre:"<<b<<endl;
			cal_area();
			cout<<"area:"<<area<<endl;
			cal_peri();
			cout<<"peri:"<<peri<<endl;
				
		}


};
int main()
{
	rectangle small;
	//small.setdata();
	//small.cal_area();
	//small.cal_peri();
	small.display();
}
