#include<iostream>
using namespace std;
class array
{
	int **ptr;
	int size,r,c,i,j;
	public:void setdata()
		{
			//cout<<"enter size"<<endl;
			//cin>>size;
			cout<<"enter r,c:"<<endl;
			cin>>r>>c;
			
			ptr=new int*[r];
			cout<<"enter values to ptr:"<<endl;
			for(i=0;i<r;i++)
			{	ptr[i]=new int[c];
				for(j=0;j<c;j++)
					cin>>ptr[i][j];
			}
		}
		void display()
		{
			
			for(int i=0;i<r;i++)
			{	for(j=0;j<c;j++)
				cout<<ptr[i][j]<<" ";
				cout<<endl;
			}
		}
		void sort()
		{
			int i,j;
			for(int k=0;k<r;k++)
			for(i=0;i<r;i++)
				for(j=i+1;j<r;j++)
					if(ptr[k][i]>ptr[k][j])
						swap(k,i,j);	
		}
		/*void reverse()
		{
			int i,j;
			for(i=0,j=size-1;i<j;i++,j--)
				swap(i,j);
		}*/
		void swap(int k,int i,int j)
		{
			int temp;
			temp=ptr[k][i];
			ptr[k][i]=ptr[k][j];
			ptr[k][j]=temp;

		}
		/*int search()
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
		}*/
		void menu()
		{
			int ch,i;
			setdata();
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
					//case 4:reverse();
					       cout<<"element after rev:"<<endl;
						display();break;
					//case 5:i=search();
						if(i==-1)	
						  cout<<"not found"<<endl;
						else
						  cout<<"found at "<<i<<endl;
						break;		
					//case 6:delarray();break;
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
