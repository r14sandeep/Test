#include<iostream>
using namespace std;
class Time
{
	int h,m,s;
public:
	Time(int v1=0,int v2=0,int v3=0)
	{
		h=v1;m=v2;s=v3;
	}
	void settime(int v1,int v2,int v3)
	{h=v1;m=v2;s=v3;}
	void print()
	{
		if(h>23||m>59||s>59)
		{
			throw "Exception:invalid invalid time";
		}
		cout<<h<<":"<<m<<":"<<s<<endl;
	}
	void sethour(int v)
	{
		h=v;
	}
	void setminute(int v)
	{
		m=v;
	}
	void setsecond(int v)
	{
		s=v;
	}
	int gethour()
	{return h;}
	int getminute()
	{return m;}
	int getsecond()
	{return s;}
	void nextsecond()
	{
		if(s+1>59)
		{
			s=0;
			m++;
			if(m==60)
			{
				m=0;
				h++;
				if(h==24)
					h=0;
			}
			
		}
		else
			s=s+1;

	}

};
int main()
{
	Time t1(23,59,59);
	t1.print();
	t1.sethour(12);
	t1.setminute(30);
	t1.setsecond(15);
	t1.print();
	cout<<"hour is:"<<t1.gethour()<<endl;
	cout<<"minute is:"<<t1.getminute()<<endl;
	cout<<"second is:"<<t1.getsecond()<<endl;

	Time t2;
	t2.print();
	t2.settime(1,2,3);
	t2.print();

	Time t3(12);
	t3.print();

	Time t4(23,59,58);
	t4.print();
	t4.nextsecond();
	t4.print();
	
	t4.nextsecond();
	t4.print();
	
	Time t5(25,61,99);
	try{
	
	t5.print();
	}
	catch(const char *error)
	{
		cout<<error<<endl;
	}

}
