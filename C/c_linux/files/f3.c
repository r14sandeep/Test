#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;
	int cnt=0;
	fp=fopen(argv[1],"r");	
	printf("=========>%c\n",argv[2][0]);
	switch(argv[2][0])	
	{
		case 'l':while((ch=fgetc(fp)!=EOF))
			 {
				 if(ch=='\n')
				 cnt++;
			 }
			 printf("line cnt=%d\n",cnt);break;
		case 'w':while((ch=fgetc(fp))!=EOF)
				 if(ch==' ')
					 cnt++;
			 printf("word cnt%d\n",cnt);break;


	}
	printf("%d\n",cnt);
	fclose(fp);


}
