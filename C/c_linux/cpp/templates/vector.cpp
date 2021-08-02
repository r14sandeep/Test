#include<iostream>
using namespace std;
template<class any>
class vector
{
	any *ptr;
	int size;
	public:vector()
		{
			cout<<"enter no.of ele"<<endl;
			cin>>size;
			ptr=new any[size];
			for(int i=0;i<size;i++)
				cin>>ptr[i];
		}
		void display()
		{
			cout<<"ele are:"<<endl;
			for(int i=0;i<size;i++)
				cout<<ptr[i]<<" ";
			cout<<endl;
			cout<<sizeof(any);
		}
		void sort()
		{
			int i,j;
			for(i=0;i<size-1;i++)
				for(j=i+1;j<size;j++)
					if(ptr[i]>ptr[j])
						swap(i,j);
		}
		void swap(int i,int j)
		{
			int temp;
			temp=ptr[i];
			ptr[i]=ptr[j];
			ptr[j]=temp;
			
		}	

};
main()
{
	vector<int>obj1;
	obj1.display();
	obj1.sort();
	cout<<"after sort"<<endl;
	obj1.display();

}
