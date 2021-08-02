#include<iostream>
using namespace std;
struct play
{
int s,b;

};
void cal(play &p,int n=10)
{
p.s++;
p.b+=n;
}
main()
{
	play pl={10,15};
	cal(pl,5);
	cout<<pl.s<<":"<<pl.b<<endl;
	cal(pl);
	cout<<pl.s<<":"<<pl.b<<endl;
	cal(pl,15);
	cout<<pl.s<<":"<<pl.b<<endl;

}
