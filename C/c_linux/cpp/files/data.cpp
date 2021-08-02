#include<iostream>
#include<fstream>
using namespace std;
main()
{
	//float a[8]={1.2,2.5,22.1,44.2,6.2,3.9,1.45,34.5};
	int a[6]={1,3,2,4,8,9};
	fstream file;
	char b[10];
	file.open("data",ios::in|ios::out);
	file.read((char *)&b,sizeof(b));
	file.write((char *)&a,sizeof(a));
	file.seekg(0);
	for(int i=0;b[i];i++)
	{
	//cout<<"****"<<endl;	
	cout<<b[i]<<" ";
	}
	cout<<endl;
	file.close();

}
