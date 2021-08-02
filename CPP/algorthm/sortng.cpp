#include<iostream>
#include<algorithm>
using namespace std;
void show(int a[])
{
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[10]={7,5,6,9,1,10,32,4,33,55};
	show(a);
	sort(a,a+5);
	show(a);
	return 0;
}
