#include<iostream>
using namespace std;
class height
{
	int feet,inch;
	public:void getht(int f,int i)
		{
			feet=f;
			inch=i;
		}
		void putht()
		{
			cout<<"height is:"<<feet<<"feet\t"<<inch<<"inches"<<endl;
			
		}
		void sum(height ,height );

};
void height::sum(height a,height b)
{
	height n;
	n.feet=a.feet+b.feet;
	n.inch=a.inch+b.inch;
	if(n.inch==12)
	{
		n.feet++;
		n.inch=n.inch-12;
	}
	cout<<"height is:"<<n.feet<<"feet\t"<<n.inch<<"inches"<<endl;
			
}

//};
int main()
{
	height h,d,a;
	h.getht(6,5);
	a.getht(2,7);
	h.putht();
	a.putht();
	d.sum(h,a);

}
