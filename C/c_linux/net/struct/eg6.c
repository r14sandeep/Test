#include<stdio.h>
struct course
{
	int cno;
	char cname[20];
};
main()
{
	struct course c[]={{102,"java"},{103,"php"},{104,"cpp"}};
	printf("%d ",c[1].cno);
	printf("%s\n",(*(c+2)).cname);
	


}
