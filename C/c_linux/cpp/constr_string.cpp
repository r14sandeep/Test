 #include<iostream>
#include<string>
using namespace std;
class String
{
	char *ptr;
	int size;
	public:String()
		{
			cout<<"in default constr"<<endl;
			cout<<"enter size"<<endl;
			cin>>size;
			ptr=new char[size];
			cout<<"enter string:"<<endl;
			cin>>ptr;
		}
		String(const char *p)
		{
			size=strlen(p)+1;
			ptr=new char [size];
			strcpy(ptr,p);
		}
		String(String &s)
		{
			size=s.size;
			ptr=new char[size];
			strcpy(ptr,s.ptr);
		}
		void display()
		{
			cout<<"size:"<<size<<"ptr:"<<ptr<<endl;

		}
		~String()
		{
			cout<<"destructed"<<endl;
			delete[]ptr;
			ptr=NULL;

		}

};
main()
{
	String s;
	cout<<"details of s"<<endl;
	s.display();
	
	String s1("vector");
	cout<<"details of s1"<<endl;
	s1.display();

	String s3=s;
	cout<<"details of s3"<<endl;
	s3.display();
}
