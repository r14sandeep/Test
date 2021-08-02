#include<stdio.h>
void print(int v)
{
printf("in print v=%d\n",v);
if(v<=3)
	print(v+1);
printf("returning v=%d\n",v);

return;
}
main()
{
	int v=1;
printf("in main v=%d\n",v);
print(v);
printf("returning to main v=%d\n",v);

}
