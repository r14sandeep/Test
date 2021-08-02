#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch;
	fp=fopen(argv[1],"r");
	ch=fgetc(fp);
	printf("%c",ch);
	ch=*(fp->_IO_read_ptr++);
	printf("%c",ch);
//	ch=*(fp->_IO_read_ptr++);
//	printf("%c",ch);

	

}
