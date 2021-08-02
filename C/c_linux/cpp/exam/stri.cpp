#include<iostream>
using namespace std;
int main()
{
	string st("first string");
//	string st2(st);
	string st2="asb";
	cout<<st<<endl;
	cout<<st2<<endl;
	cout<<st2.size()<<endl;
	cout<<st.compare(st2)<<endl;
	cout<<"substr:"<<st.substr(0,3);
}
