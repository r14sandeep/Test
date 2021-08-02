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
	int n,roll2del,i;
	FILE *fp;
	struct student *buf;
	fp=fopen("stdata","r");	
	fseek(fp,0,2);
	n=(ftell(fp))/(sizeof(struct student));
	rewind(fp);
	buf=(struct student *)calloc(n,sizeof(struct student));
	fread(buf,sizeof(struct student),n,fp);
	fclose(fp);
	printf("enter the roll to be deleted");
	scanf("%d",&roll2del);
	for(i=0;i<n;i++)
	{
		if((buf+i)->roll==roll2del)
		{	memmove(buf+i,buf+i+1,(n-i-1)*sizeof(struct student));
			break;
		}
		if(i==n)
		{
			printf("not found\n");
			exit(0);
		}
		//memmove(buf+i,buf+i+1,(n-i-1)*sizeof(struct student));
	}	
	fp=fopen("stdata","w");
	fwrite(buf,sizeof(struct student),n-1,fp);
	fclose(fp);
	
}
