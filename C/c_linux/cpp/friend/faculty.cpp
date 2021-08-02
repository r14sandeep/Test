#include<iostream>
using namespace std;
class student;
class faculty
{
	char name[20];
	char sub[20];
	public:faculty()
		{
			cout<<"enter details name,sub:"<<endl;
			cin>>name>>sub;
		}
		void display()
		{
			cout<<"name:"<<name<<endl;
			cin>>"sub:"<<sub<<endl;
		}
friend void uploadmarks(student &);
};
class student
{
	int roll;
	char name[20];
	float m1,m2,m3;
	public:student()
		{
			cout<<"enter roll,name:"<<endl;
			cin>>roll>>name;
			m1=m2=m3=0.0;
		}
		void display()
		{
			cout<<"roll:"<<roll<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"m1:"<<m1<<endl;
			cout<<"m2:"<<m2<<endl;
			cout<<"m3:"<<m3<<endl;
		}
friend void uploadmarks(student &);
};
void faculty::uploadmarks(student &obj)
{
	cout<<"enter marks"<<endl;
	cin>>obj.m1>>obj.m2>>obj.m3;

}
main()
{
	faculty fobj;
	cout<<"details of faculty:"endl;
	fobj.display();
	
	student sobj;
	fobj.uploadmarks(sobj);
	cout<<"details of student:"<<endl;
	sobj.display();

}

