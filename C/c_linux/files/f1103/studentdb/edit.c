#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student 
{
	int roll;
	float mark;
	char name[20];

};
main()
{
	FILE *fp;
	int i,j,n,roll2edit,m;
	char a[20];
	float mrk;
	struct student *buf,temp;
//	struct student temp;
	//int *temp;
	
	fp=fopen("stdata","r");
	fseek(fp,0,2);
	n=ftell(fp)/sizeof(struct student);
	rewind(fp);
	buf=calloc(n,sizeof(struct student));
	fread(buf,sizeof(struct student),n,fp);
	fclose(fp);
	printf("enter roll of candidate to be edited:");
	scanf("%d",&roll2edit);
	for(i=0;i<n;i++)
	{
		if((buf+i)->roll==roll2edit)
			break;

	}
	printf("\n1-edit roll\n2-edit name\n3-edit marks\n");
	scanf(" %d",&j);
	switch(j)
	{
		case 1:printf("%d\n",buf[i].roll);
			printf("enter new  roll:");
			scanf("%d",&m);
			buf[i].roll=m;break;
/*		case 2:printf("%s",buf[i].name);
			printf("enter new name:");
			gets(a);
			buf[i].name=a;
			break;
*/
		case 3:printf("%f",buf[i].mark);
			printf("enter new marks:");
			scanf("%f",&mrk);
			buf[i].mark=mrk;break;
		default:printf("invalid data\n");break;
	}



	fp=fopen("stdata","w");
	fwrite(buf,sizeof(struct student),n,fp);
	fclose(fp);
}
