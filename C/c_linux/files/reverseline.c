#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char buf[100],temp[100];
	int i,size,a,k;
	fp=fopen(argv[1],"r");
	fgets(buf,100,fp);
	a=strlen(buf);
	k=a-1;
	for(i=0;i<a;i++)
		temp[i]=buf[k--];
//	buf=temp;
	puts(temp);




}
