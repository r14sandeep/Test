#include<iostream>
class rect
{
	private:
		int x,y;
	public:
		void setval(int,int);
		int area()
		{
			return x*y;	
			
		}

};
void rect::setval(int a,int b)
{
	x=a;y=b;

}
int main()
{
	rect var;
	var.setval(4,5);
	std::cout<<"area:"<<var.area()<<std::endl;
}
