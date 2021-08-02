#include<stdio.h>
struct student
{
	int roll;
	float mark;
	char name[20];
	
};

main()
{
	struct student v;
	FILE *fp;
	fp=fopen("stdata","r");
	while(fread(&v,sizeof(v),1,fp)==1)
		printf("%-4d%-20s%-5.2f\n",v.roll,v.name,v.mark);
	fclose(fp);



}
