#include<iostream>
using namespace std;
main()
{
	int **ptr;
	int r,c,i,j;
	cout<<"enter r,c"<<endl;
	cin>>r>>c;
	ptr=new int*[r];
	for(i=0;i<r;i++)
	{
		ptr[i]=new int[c];
		cout<<"enter col values:"<<endl;
		for(j=0;j<c;j++)
			cin>>ptr[i][j];
	}
	cout<<"elements are:"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<ptr[i][j]<<" ";
		cout<<endl;
	}
	for(i=0;i<r;i++)
	{
		delete[]ptr[i];
		ptr[i]=NULL;
	}
	delete ptr;
	ptr=NULL;
	
}
