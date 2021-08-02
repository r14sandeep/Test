#include<iostream>
using namespace std;
class String
{
	char *ptr;
	int size;
	public:String()
		{
			ptr=NULL;size=0;
		}
		String(const char *p)
		{
			size=strlen(p)+1;
			ptr=new char(size);
			strcpy(ptr,p);
		}
		int operator==(String &);
		void operator=(String &);
		String operator+(String &);
		void display()
		{
			cout<<"size:"<<size<<endl;
			cout<<"ptr:"<<ptr<<endl;
		}
		~String()
		{
			cout<<"string destroyed"<<endl;
			delete[]ptr;
			ptr=NULL;
		}
};
int String:: operator==(String &s)
{
	int i=0;
	if(size==s.size)
	{
		while(ptr[i])
		{
			if(ptr[i]!=s.ptr[i])
				break;
			i++;
		}
		if(i==size-1)
			return 1;
	}
	return 0;

}
void String:: operator=(String &s)
{
//	String temp;
//	temp.size=s.size;
//	temp.ptr=new char(temp.size);
	size=s.size;
	ptr=new char(size);
	strcpy(ptr,s.ptr);
//	strcpy(temp.ptr,s.ptr);
//	return temp;
}
String String::operator+(String &s)
{
	String temp;
	/*size=s1.size+s2.size;
	ptr=new char(size);
	strcpy(ptr,s1.ptr);	
	strcat(ptr,s2.ptr);*///
	temp.size=size+s.size;
	temp.ptr=new char(temp.size);
	strcpy(temp.ptr,ptr);
	strcat(temp.ptr,s.ptr);
	return temp;

}
main()
{
	String str1("vector");
	//str.display();
	//String str1;
	str1.display();
	char ch[20];
	cout<<"enter string:";
	cin>>ch;
	String str2(ch);
	str2.display();
	if(str1==str2)
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	String str3;

	str3=str2;
	puts("str3");
	str3.display();


	String str4;
	str4=str1+str3;
	cout<<"str4:"<<endl;
	str4.display();
}
