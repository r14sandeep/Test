#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student 
{
	int roll;
	float mark;
	char name[20];
	
};

main()
{
	struct student *buf;
	FILE *fp;
	int i,j,n,k;
	fp=fopen("stdata","r");
	fseek(fp,0,2);
	n=ftell(fp)/sizeof(struct student);
	rewind(fp);
	buf=calloc(n,sizeof(struct student));
	fread(buf,sizeof(struct student),n,fp);
	fclose(fp);
	
		
	for(i=0;i<n;i++)
	    for(j=i+1;j<n;j++)
		
	  if(((buf+i)->roll==(buf+j)->roll)||(strcmp((buf+i)->name,(buf+j)->name)==0))
	      {	
		printf("duplicate found at i=%d,j=%d\n",i,j);
		printf("dup of i=%d:%-4d%-20s%5.2f\n",i,buf[i].roll,buf[i].name,buf[i].mark);
		printf("  is   j=%d:%-4d%-20s%5.2f\n",j,buf[j].roll,buf[j].name,buf[j].mark);
		
		//printf("is j=%s\n",buf[j]);
		printf("enter which record u want to delete w.r.t i=%d,j=%d value\n",i,j);
		scanf("%d",&k);
		memmove(buf+k,buf+k+1,(n-k-1)*sizeof(struct student));
		n--;
		j--;
		}
		
	fp=fopen("stdata","w");
	fwrite(buf,sizeof(struct student),n,fp);
	fclose(fp);
	//for(i=0;i<n-cnt;i++)
	//	printf("%-4d%-20s%-5.2f\n",(buf+i)->roll,(buf+i)->name,(buf+i)->mark);
}
