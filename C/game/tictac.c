#include<iostream>
#include<cstring>

using namespace std;
char tictac[3][3];
//bzero(tictac,sizeof(tictac));
class game
{
private:
	string name;
	char symbol;
	int x,y;
public:
	game()
	{
		cout<<"enter player name:";
		cin>>name;
		cout<<"enter symbol:";
		cin>>symbol;
	}
	int play()
	{
		cout<<name<<" enter x,y:";
		cin>>x>>y;
		if(tictac[x][y]==0)
		{
			tictac[x][y]=symbol;
			return 0;
		}
		else
		{
			cout<<"enter valid position please enter again:"<<endl;
			return 1;
		}
	}


	int status()
	{
		int temp,i,j,cnt;
		for(int i=0;i<3;i++)
		{
			temp=tictac[i][0];
			cnt=0;
			for(int j=0;j<3;j++)
			{
				if(temp!=0)
				if((temp==tictac[i][j]))
					cnt++;
			}
			if(cnt==3)
			{
				//if(a[i][j])
				cout<<"***** "<<name<<" ****** has won"<<endl;
				return 0;
			}
		}
		for(int i=0;i<3;i++)
		{
			temp=tictac[0][i];
			cnt=0;
			for(int j=0;j<3;j++)
			{
				if(temp!=0)
				if((temp==tictac[j][i]))
					cnt++;
			}
			if(cnt==3)
			{
				//if(a[i][j])
				cout<<"***** "<<name<<" ****** has won"<<endl;
				return 0;
			}
		}
		return 1;
	}	

	void display()
	{
		int i,j;
		for(int i=0;i<3;i++,cout<<"\n")
		{
			for(int j=0;j<3;j++)
				cout<<tictac[i][j]<<"  |";
		}


	}

};
int main()
{
	int i,st;
	memset(tictac,0,sizeof(tictac));
	game p1[2];
//	game p2;
	while(1)
	{
		for(int j=0;j<2;j++)
		{
			i=p1[j].play();
			p1[j].display();
			if(i==1)
				j--;
			else
			{
				st=p1[j].status();
				if(st==0)
					return 0;
			}
		}
		//i=p1[1].play();
		//display();
	}
	

	
	


}
