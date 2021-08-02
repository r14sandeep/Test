/*manage the i/p not to get repeated when i/p is random data*/

#include<stdio.h>
main()
{
	int i,j,n,a[20];
	n=sizeof(a)/sizeof(a[0]);
	srand(getpid());
	for(i=0;i<n;i++)
	{
loop:		a[i]=65+(rand()%58);
	//	printf("a[%d]=%d,",i,a[i]);

		if((a[i]>90)&&(a[i]<97))
		{	printf("spcl char,i/p again");
			//a[i]='a';
			goto loop;	
		}
		else{	
			for(j=0;j<i;j++)
			{
				if(a[i]==a[j])
				{	printf("repeatd data,so i/p again");
					goto loop;
				}
		}	
		}
	printf("a[%d]=%c\n",i,a[i]);

	}



}
