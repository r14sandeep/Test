#include"myheader.h"
void save(STUDENT *ptr,int cnt)
{
	FILE *fp;
	fp=fopen("student.data","w");
	fwrite(ptr,sizeof(STUDENT),cnt,fp);
	fclose(fp);
}
