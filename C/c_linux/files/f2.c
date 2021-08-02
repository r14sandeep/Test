#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*buf,str[50];
	int w_cnt=0,l_cnt=0,c_cnt=0;

	fp=fopen(argv[1],"r");
	while(fscanf(fp,"%s",str)!=EOF)		
	{
		w_cnt++;
	}
	rewind(fp);
	while(fgets(str,80,fp)!=NULL)		
	{
		l_cnt++;
	}
	rewind(fp);
	while(ch=fgetc(fp)!=EOF)
	{
		c_cnt++;

	}
	printf("line cnt=%d\n",l_cnt);
	printf("word cnt=%d\n",w_cnt);
	printf("char cnt=%d\n",c_cnt);
}
