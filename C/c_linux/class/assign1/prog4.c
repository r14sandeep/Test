//prog to print the binary,decimal equi and its symbol of all the chars:
#include<stdio.h>
main()
{
	char v=0;
	int bit;
loop1: if((v>=0)&&(v<128)){
	    printf("\n %d %c ",v,v);
	    bit=7;
loop2:if(bit>=0)
	{
		printf("%d",(v>>bit)&1);
	        bit--;
		goto loop2;
	}
	v++;
	if(v%10==0)
		getchar();
	goto loop1;
}
}
