#include<iostream>
using namespace std;
class student
{
	int roll;
	char name[20];
	float per;
	public:student()////////default constructor///////////
		{
			cout<<"enter roll,name,per"<<endl;
			cin>>roll>>name>>per;
		}
		student(int r,const char *n,float p)//parameter contructor////
		{
			roll=r;
			strcpy(name,n);
			per=p;
		}
		student(student &s)
		{
			roll=s.roll;
			strcpy(name,s.name);
			per=s.per;
		}
		void display()
		{
			cout<<"roll:"<<roll<<"  ";
			cout<<"name:"<<name<<"  ";
			cout<<"per:"<<per<<endl;
			

		}

};
main()
{
	student a1;
	//a1.student();
	cout<<"details of a1"<<endl;
	a1.display();
	cout<<"details of b1:"<<endl;
	student b1(18,"deepu",80);
	b1.display();
	student c1=a1;
	
	cout<<"details of c1"<<endl;
	c1.display();

}
