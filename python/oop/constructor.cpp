#include<iostream>
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

}
