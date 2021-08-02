#include<iostream>
#include<cstring>
using namespace std;
class student
{
	char name[20];
	int roll;
	float per;
	public:
		student()
		{
			cout<<"in default constructor"<<endl;
			cout<<"enter name,roll,percentage:"<<endl;
			cin>>name>>roll>>per;
		}
		student(int x,const char *n,float f)
		{
			cout<<"in parameterised constructor"<<endl;
			strcpy(name,n);
			roll=x;per=f;
		}
		student(student &s)
		{
			cout<<"in copy constructor"<<endl;
			roll=s.roll;
			strcpy(name,s.name);
			per=s.per;
		}
		void display()
		{
			cout<<"name:"<<name<<endl;
			cout<<"roll:"<<roll<<endl;
			cout<<"per:"<<per<<endl;
		}

};

int main()
{
	student obj;
	obj.display();
	student obj1(33,"deepu",35);
	obj1.display();
	student obj2=obj1;
	obj2.display();
}
