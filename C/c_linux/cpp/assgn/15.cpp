#include<iostream>
using namespace std;


main()
{
int x=10,y=20;
int *p=&x;
int &z=y;
*p++;
z++;
cout<<x<<" "<<y<<endl;
return 0;
}
