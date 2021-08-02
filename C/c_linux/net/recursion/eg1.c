#include<stdio.h>
int f(int cnt)
{
printf("%d\n",cnt);
if(cnt<3)
	f(f(++cnt));
return cnt;
}
main()
{
f(1);
return 0;


}
