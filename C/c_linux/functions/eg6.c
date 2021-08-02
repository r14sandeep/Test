#include<stdio.h>
void print(int v)
{
printf("in print v=%d\n",v);
if(v<=3)
	print(++v);
printf("returning v=%d\n",v);

return;

}
main()
{
int v=1;
//printf("%d\n",v);
print(v);
printf("in main v=%d\n",v);


}
