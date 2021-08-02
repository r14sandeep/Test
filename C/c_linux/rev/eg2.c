#include<stdio.h>
#include<math.h>
main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
/*	while(1)
	{
		printf("1-dec to oct\n2-dec to hex\n3-oct to dec\n4-hex to dec\n5-hex to oct\n");
		printf("enter ur choice:");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:dectooct(n);break;
			case 2:dectohex(n);break;
		//	case 3:octtodec();
			default:printf("invalid\n");break;
		}

	}
}
void dectooct(int n)
{*/
	int temp,cnt=0,res=0;
	while(n>=8)
	{
		temp=n%8;
		n=n/8;
		cnt++;
			res=res+(temp*pow(10,cnt-1));

	}
			res=res+(n*pow(10,cnt));
	printf("octal value is %d\n",res);
}
/*void dectohex(int n)
{
	int temp,cnt=0,res=0;
	while(n>=16)
	{
		temp=n%16;
		n=n/16;
		cnt++;
		if(temp>9)
		{
			if(temp==10)

		}

	}

}*/
