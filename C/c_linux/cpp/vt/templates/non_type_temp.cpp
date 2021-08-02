#include<iostream>
using namespace std;
template <class T,int N>
class myclass
{
	T memblock[N];
public:
	void setmember(int x,T val);
	T getmem(int x);

};

template<class T,int N>
void myclass<T,N>::setmember(int x,T val)
{
	memblock[x]=val;
}
template <class T,int N>
T myclass<T,N>::getmem(int x)
{
	return memblock[x];
}
int main()
{
	myclass<int,1> myint;
	myclass<double,3> myfloat;
	myint.setmember(2,123);
	myfloat.setmember(44,23.34);
	cout<<myint.getmem(2)<<endl;
	cout<<myfloat.getmem(44)<<endl;
}
