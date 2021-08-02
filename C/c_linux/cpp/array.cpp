#include<iostream>
using namespace std;
class array
{
	int *ptr;
	int size;
	public:void setdata()
		{
			cout<<"enter size"<<endl;
			cin>>size;
			ptr=new int[size];
			cout<<"enter values to ptr:"<<endl;
			for(int i=0;i<size;i++)
				cin>>ptr[i];
		}
		void display()
		{
			
			for(int i=0;i<size;i++)
				cout<<ptr[i]<<" ";
			cout<<endl;
		}
		void sort()
		{
			int i,j;
			for(i=0;i<size-1;i++)
				for(j=i+1;j<size;j++)
					if(ptr[i]>ptr[j])
						swap(i,j);	
		}
		void reverse()
		{
			int i,j;
			for(i=0,j=size-1;i<j;i++,j--)
				swap(i,j);
		}
		void swap(int i,int j)
		{
			int temp;
			temp=ptr[i];
			ptr[i]=ptr[j];
			ptr[j]=temp;

		}
		int search()
		{
			int data;
			cout<<"enter data to be searched:"<<endl;
			cin>>data;
			for(int i=0;i<size;i++)
			{
				if(ptr[i]==data)
					return i;
			}
			return -1;
		}
		void delarray()
		{
			delete[]ptr;
			ptr=NULL;
		}
		void menu()
		{
			int ch,i;
			while(1)
			{
				cout<<"1.setdata\n2.display\n3.sort\n4.reverse\n5.search\n6.delete\n"<<endl;
				cout<<"enter ch:"<<endl;
				cin>>ch;
				switch(ch)
				{
					case 1:setdata();break;
					case 2:display();break;
					case 3:sort();
					      cout<<"elements are sorted"<<endl;
						display();break;
					case 4:reverse();
					       cout<<"element after rev:"<<endl;
						display();break;
					case 5:i=search();
						if(i==-1)	
						  cout<<"not found"<<endl;
						else
						  cout<<"found at "<<i<<endl;
						break;		
					case 6:delarray();break;
					case 7:return;
					default:cout<<"invalid data"<<endl;break;
				}
			}

		}

};
main()
{
	array obj1;
	obj1.menu();
	//obj1.setdata();
	//obj1.display();

}
