#include<stdio.h>
int main() {
	//code
	int n,rem,cnt=0;
	scanf("%x",&n);
	while(n!=0)
	{
	    cnt++;
	    rem=n%16;
	    printf("r:%x ",rem);
	    n/=16;
	    	    printf("n:%d ",n);
		if(n==0)
			break;
	}
	printf("\nn:%x",n);
	//printf("%d",pow(2,cnt));
	//printf("%d\n",cnt);
	int res=2;
	while(cnt)
	{
	    res*=res;
	    cnt-=2;
	}
	printf("\n %d %d\n",cnt,res);
	
	return 0;
}
