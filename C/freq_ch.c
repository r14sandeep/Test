#include<stdio.h>
int main()
{
	char str[10];
	int cnt=0;
	gets(str);
	int index1,index2;
	for(index1=0;str[index1];index1++)
	{
		for(index2=index1-1;index2>=0;index2--)
			if(str[index1]==str[index2])
				break;
		if(index2<0)
		{
			cnt=0;
			for(index2=index1;str[index2];index2++)
				if(str[index2]==str[index1])
					cnt++;
			printf("%c present %d times\n",str[index1],cnt);
		}
	}

}
