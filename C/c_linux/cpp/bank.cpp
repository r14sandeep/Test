#include<iostream>
using namespace std;
class bank
{
	int accno;
	char name[20];
	float bal;
	void setdata()
	{
		cout<<"enter acc,name,bal:"<<endl;
		cin>>accno>>name>>bal;
	}
	void diposit(float amt)
	{
		//float amt;
		//cout<<"enter the amount to be deposited:"<<endl;
		//cin>>amt;
		bal+=amt;
	}
	int withdrawl(float amt)
	{
		//float amt;
		//cout<<"enter the amount to be withdrawl:"<<endl;
		//cin>>amt;
		if(amt<bal)
		{
			bal-=amt;
		}
		else
		{
			cout<<"insufficient fund"<<endl;return 0;
		}

	}
	void balenq()
	{
		cout<<"amt in ur acc is:"<<bal<<endl;
	}
	void display()
	{
		cout<<"accno"<<accno<<endl;
		cout<<"name:"<<name<<endl;
		cout<<"bal:"<<bal<<endl;
	}
	public:void menu()
		{
			int choice,amt;
			setdata();
			while(1)
			{
				cout<<"1.deposit\n2.withdrawl\n3.balenq\n4.display\n5.quit"<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1:cout<<"enter the amt"<<endl;
					cin>>amt;
					diposit(amt);
					balenq();
					break;
				case 2:cout<<"enter amt"<<endl;
					cin>>amt;
					if(withdrawl(amt))
						cout<<"withdrawl success"<<endl;
					balenq();break;
				case 3:balenq();break;
				case 4:display();break;
				case 5:return;
				default:cout<<"invlid choice"<<endl;
			} 

			}
		}

};
main()
{
	bank myacc;
	cout<<"myacc:"<<endl;
	myacc.menu();
}
