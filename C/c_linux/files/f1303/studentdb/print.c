#include"myheader.h"
void print(STUDENT *ptr,int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%-4d%-20s%.2f\n",ptr[i].roll,ptr[i].name,ptr[i].mark);


}
