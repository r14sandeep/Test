#include<iostream>
using namespace std;
class sample
{
	private:
		int v1;
	public:
		void set_v1(int);
		int get_v1(void);

};
void sample::set_v1(int v)
{
	v1=v;
}
int sample::get_v1()
{
	return v1;
}
int main()
{
	class sample obj;
	obj.set_v1(22);
	cout<<obj.get_v1()<<endl;

}
