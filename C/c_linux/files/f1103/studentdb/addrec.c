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
	printf("enter name:");
	scanf("%s",&v.name);
	printf("enter mark:");
	scanf("%f",&v.mark);
	printf("enter roll:");
	scanf("%d",&v.roll);
	fp=fopen("stdata","a");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	fwrite(&v,sizeof(v),1,fp);

	fclose(fp);
	printf("data entered successfully\n");
}

