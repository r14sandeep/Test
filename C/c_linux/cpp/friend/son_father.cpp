#include<iostream>
using namespace std;
class son;
class father
{
	char name[20];
	int age;
	char cmp[20],design[20];
	float sal,exp,totexp;
	public:father()
		{
			cout<<"enter f details name,age,cmp,design,sal,exp:"<<endl;
			cin>>name>>age>>cmp>>design>>sal>>exp;
		}
		void display()
		{
			cout<<"details of father:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"age:"<<age<<endl;
			cout<<"cmp:"<<cmp<<endl;
			cout<<"design:"<<design<<endl;
			cout<<"sal:"<<sal<<endl;
			cout<<"exp:"<<exp<<endl;
			cout<<"totexp:"<<totexp<<endl;
		}
		void cal_totexp(son &);
		void saving()
		{
			cout<<"saving:"<<sal-totexp<<endl;
		}
		void detailsofson(son &);
		~father()
		{
			cout<<"father destructed"<<endl;
		}
		friend class son;
};
class son
{
	char name[20],qual[10],clg[20];
	int age;
	float pm;//pocket money
	float exp;
	public:son()
		{
			cout<<"enter the details name,age,qual,clg,pm,exp:"<<endl;
			cin>>name>>age>>qual>>clg>>pm>>exp;
		}
		void display()
		{
			cout<<"details of son:"<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"age:"<<age<<endl;
			cout<<"qual:"<<qual<<endl;
			cout<<"clg:"<<clg<<endl;
			cout<<"pm:"<<pm<<endl;
			cout<<"exp:"<<exp<<endl;
		}
void fatherdetails(father &);
		~son()
		{
			cout<<"son destructor"<<endl;
		}
		friend class father;
	
};
void father::cal_totexp(son &obj)
{
	totexp=exp+obj.exp+obj.pm;

}
void father::detailsofson(son &obj)
{
	cout<<"details of my son:"<<endl;
	cout<<"name:"<<obj.name<<"\nqual:"<<obj.qual<<"\ncolg:"<<obj.clg<<endl;
}
void son::fatherdetails(father &f)
{
	cout<<"my father details:"<<endl;
	cout<<"name:"<<f.name<<"\ncmp:"<<f.cmp<<"\ndesign:"<<f.design<<endl;

}
main()
{
	father fobj;
	son sobj;
	fobj.cal_totexp(sobj);
	fobj.saving();
	fobj.display();
	fobj.detailsofson(sobj);
	sobj.display();
	sobj.fatherdetails(fobj);

}
