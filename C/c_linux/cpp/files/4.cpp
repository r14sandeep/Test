#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
main()
{
	char line[80];
	int cnt=0,i;
	ifstream fin;
	ofstream fout;
	fin.open("data",ios::in);
	fout.open("temp",ios::out);
	while(fin)
	{
		fin.getline(line,80);
		fout<<line<<endl;
	}
	fin.close();
	fout.close();
/*	fin.open("temp",ios::in);
	while(fin)
	{
		fin.getline(line,80);

	}
	fin.close();
*/
}
