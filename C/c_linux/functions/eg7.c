#include<stdio.h>
int v=1;
main()
{
printf("in mian v=%d\n",v);
++v;
if(v<=3)
main();
printf("returning to main v=%d\n",v);


}
