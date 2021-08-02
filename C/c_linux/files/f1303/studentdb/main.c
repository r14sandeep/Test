#include"myheader.h"
#include<signal.h>
//void save(int );
main()
{
	int cnt=0,ch,n;
	STUDENT *buf=0;
//	syncdatabase(&buf,&cnt);
	while(1)
	{
//		alarm(5);
		printf("1:addrec\n2:printrec\n3:save\n4:delete\n5:quit\n");
		printf("make ur choice\n");
		scanf(" %d",&ch);
//		signal(SIGALRM,save);
		switch(ch)
		{
			case 1:add(&buf,&cnt);break;
			case 2:print(buf,cnt);break;
			case 3:save(buf,cnt);break;		
		}

	
	}





}
