#include<stdio.h>
struct student
{
	int roll;
	char name[20];
	float marks;
	struct{

		int dd,mm,yy;//date,month,year

	}dob;


};
int cnt=0;
main()
{
	struct student v;
	char ch;
	while(1)
	{
		printf("***MENU****\n");
		printf("i-input\np-print\nd-delete\ns-sort\n");
		printf("enter ur choice:");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':input(&v);break;
			case 'p':print(&v);break;
			case 's':sort(&v);break;
			default:printf("invalid option\n");break;
		}


	}


}
void input(struct student *p)
{
	printf("'enter roll no:");
	scanf("%d",&(p+cnt)->roll);
	puts("enter name");
	getchar();
	gets((p+cnt)->name);
	printf("enter maarks:");
	scanf("%f",&(p+cnt)->marks);
	printf("enter dob\n");
	scanf("%d%d%d",&(p+cnt)->dob.dd,&(p+cnt)->dob.mm,&(p+cnt)->dob.yy);
	cnt++;

}



void print(struct student *p)
{

	int i;
	for(i=0;i<cnt;i++)
	{
		printf("%d %-10s %2f %d/%d/%d\n",(p+i)->roll,(p+i)->name,(p+i)->marks,(p+i)->dob.dd,(p+i)->dob.mm,(p+i)->dob.yy);
	}
}




void sort(struct student *p)
{
	int i,j;
	struct student temp;
	for(i=cnt-1;i>=0;i--)
		for(j=0;j<i;j++)
			if((p+j)->roll>(p+j+1)->roll)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;		
			}	

	


}
