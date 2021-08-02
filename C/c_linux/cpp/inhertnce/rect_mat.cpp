#include<iostream>
using namespace std;
class cpoly
{
	protected:int w,h;
	public:
		cpoly()
		{
			//w=a;h=b;
			cout<<"enter w,h:";
			cin>>w>>h;
		}
};
class ctriangle:protected cpoly
{
	public:void area()
		{cout<<(w*h/2)<<endl;}

};
class crect:public cpoly
{
		public:int area()
			{return (w*h);}
};
main()
{
	crect rect;
	ctriangle trgl;
//	rect.set_val(4,5);
//	trgl.set_val(4,5);
	cout<<rect.area()<<endl;
//	cout<<trgl.area()<<endl;
	trgl.area();
}
