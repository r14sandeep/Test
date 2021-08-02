#include<stdio.h>
void fun(char *str,char *alpha)
{
	int arr[10],i,j,k;
	char temp,ind;
	for(i=0;str[i];i++)
	{
		temp=str[i];
		for(j=0;alpha[j];j++)
			if(alpha[j]==temp)
			{
				
				ind = j;
				arr[i]=j;
				for(k=ind-1;k>=0;k--)
		                       alpha[k+1]=alpha[k];
        			alpha[0]=temp;    
//	   			puts(alpha);

				break;
			}
		
	}
	for(i=0;i<strlen(str);i++)
		printf("%d ",arr[i]);

}
int main()
{
	char str[10];//="panama";
	gets(str);
	char alpha[30]="abcdefghijklmnopqrstuvwxyz";
	fun(str,alpha);
	


}
