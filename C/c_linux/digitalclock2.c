#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int i,m,h,s,j,p[2];
	char a[100],*ch;
	m=h=s=0;
	pipe(p);
	while(1)
	{
		for(i=0;i<100000;i++)
		for(j=0;j<1000;j++);
		
	//	if(strcmp(a,"p")==0)
	//		s=s;
		//if(strcmp(a,"r")==0)
		//{
		system("clear");
		printf("%d:%d:%d\n",h,m,s);
		s++;
		if(s==60)
		{
			s=0;
			m++;
		}
		if(m==60)
		{
			m=0;
			h++;
		}
		//}
	//	system("clear");
	//	printf("%d:%d:%d",h,m,s);
		//sleep(1);
	}
		
}
