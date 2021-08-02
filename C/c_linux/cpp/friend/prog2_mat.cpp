#include<iostream>
using namespace std;
class storage
{
	private:int m_nval;
		double m_dval;
	public:storage(int nval,double dval)
		{m_nval=nval;m_dval=dval; }
		friend class display;
};
class display
{
	private:bool m_bdisplay;
	public:display(bool bdisplay){m_bdisplay=bdisplay;}
	void displayitem(storage &cstorage);
/*	void displayitem(storage &cstorage)
	{
		if(m_bdisplay)
			cout<<cstorage.m_nval<<" "<<cstorage.m_dval<<endl;
		else
			cout<<cstorage.m_dval<<" "<<cstorage.m_nval<<endl;
	}
*/
};
	void display::displayitem(storage &cstorage)
	{
		if(m_bdisplay)
			cout<<cstorage.m_nval<<" "<<cstorage.m_dval<<endl;
		else
			cout<<cstorage.m_dval<<" "<<cstorage.m_nval<<endl;
	}
main()
{
	storage cstorage(5,5.6);
	display cdisplay(false);
	cdisplay.displayitem(cstorage);

}
