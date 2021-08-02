#include<iostream>
using namespace std;
class point
{
 friend void changeprivate(point &);
	public:point(void):m_i(0){}
		//////point(void){m_i=0;}
	void printprivate(void){cout<<m_i<<endl;}
	private:int m_i;
};
void  changeprivate(point &i){i.m_i++;}
main()
{
	point spt;
	spt.printprivate();
	changeprivate(spt);
	spt.printprivate();

}
