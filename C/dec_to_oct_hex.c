#include<stdio.h>
#include<string.h>
char hex[10];
int find_oct(int val)
{
	int rem;
	rem=val%8;
        if(val!=0)
	return(rem+find_oct(val/8)*10);
}
char *find_hex(int val)
{
	int rem,index1=0,index2=0;
	char temp;
	while(val)
	{
		rem=val%16;
	        if(rem>9)
			hex[index1++]=55+rem;
		else
			hex[index1++]=48+rem;
		val/=16;
	}
	hex[index1]='\0';		
	for(index1=0,index2=strlen(hex)-1;index1<index2;index1++,index2--)
	{
		temp=hex[index1];
		hex[index1]=hex[index2];
		hex[index2]=temp;
	}
	puts(hex);
	return hex;
}
int main()
{
         int val,oct=0,temp,rem;
	char *p;
         printf("enter a decimal value:");
         scanf("%d",&val);
	oct=find_oct(val);   
	printf("oct=%d\n",oct); 
	
	p=find_hex(val);
      printf("hex=%s\n",p); 
}
