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
	int i,j,n,cnt=0;
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
	      {	memmove(buf+j,buf+j+1,(n-j-1)*sizeof(struct student));
		n--;
		j--;
		//printf("%d\n",sizeof(buf+j+1));
		//return;
		}
		
	  /*if(strcmp((buf+i)->name,(buf+j)->name)==0)
		{
	      	memmove(buf+j,buf+j+1,sizeof(buf+j+1)+1);
		cnt++;
		j--;
		}*/
	fp=fopen("stdata","w");
	fwrite(buf,sizeof(struct student),n,fp);
	fclose(fp);
	//for(i=0;i<n-cnt;i++)
	//	printf("%-4d%-20s%-5.2f\n",(buf+i)->roll,(buf+i)->name,(buf+i)->mark);
}
