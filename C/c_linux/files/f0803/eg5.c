#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;	
	ch=fgetc(fp);
	printf("%c",ch);
	ch=*(fp->_IO_read_ptr++);
	printf("%c",ch);
	ch=fgetc(fp);
	printf("%c",ch);
	

}
