#include<iostream>
using namespace std;
class circle;
class rectangle
{
	int area,peri,len,bre;
	public:rectangle()
		{
			cout<<"enter len,bre:"<<endl;
			cin>>len>>bre;
		}
		void cal_area()
		{
			area=len*bre;
		}
		void cal_peri()
		{
			peri=2*(len+bre);
		}
		friend void display(rectangle &,circle &);
};
class circle
{
	float area,peri,rad;
	public:circle()
		{
			cout<<"enter rad:"<<endl;
			cin>>rad;
		}
		void cal_area()
		{
			area=3.14*rad*rad;
		}
		void cal_peri()
		{
			peri=2*3.14*rad;
		}
		friend void display(rectangle &,circle &);
};
main()
{
	rectangle obj;
	obj.cal_area();
	obj.cal_peri();
//	display(obj);
	circle obj1;
	obj1.cal_area();
	obj1.cal_peri();
	display(obj,obj1);
}
void display(rectangle &obj,circle &obj1)
{
cout<<"rec area:"<<obj.area<<endl;
cout<<"rec peri:"<<obj.peri<<endl;
cout<<"cir area:"<<obj1.area<<endl;
cout<<"cir peri:"<<obj1.peri<<endl;


