#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student 
{
	int roll;
	float mark;
	char name[20];

};
/*struct st
{
	int roll;
};*/
main()
{
	FILE *fp;
	int i,j,n;
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
	for(i=n-1;i>=0;i--)
		for(j=0;j<i;j++)
			if((buf+j)->roll>(buf+j+1)->roll)
			{
				temp=buf[j+1];
				buf[j+1]=buf[j];
				buf[j]=temp;
			}
	fp=fopen("stdata","w");
	fwrite(buf,sizeof(struct student),n,fp);
	fclose(fp);
//	for(i=0;i<n;i++)
//	printf("%-4d%-20s%-5.2f",(buf+i)->roll,(buf+i)->name,(buf+i)->mark);
	

}
