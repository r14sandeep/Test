#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp1,*fp2;
	int i,n;
	char ch,buf[100];
//	printf("enter no.of copies");
//	scanf("%d",&n);
//	if(argc!=n+2)
//	{
//		printf("error:i/p as ./a.out filename\n");
//		return;
//
//	}
	fp1=fopen(argv[1],"r");	
	for(i=2;i<argc;i++)
	{
		
//	fp1=fopen(argv[1],"r");	
	/*if(fp1==NULL)
	{
		printf("error:file not found\n");
		return;

	}*/
	fp2=fopen(argv[i],"w");
	//while((ch=fgetc(fp1))!=EOF)
	while(fgets(buf,100,fp1)!=NULL)
	{
		fputs(buf,fp2);
	}
	rewind(fp1);
//	fclose(fp1);
	fclose(fp2);
	}
	fclose(fp1);

	printf("copysuccess\n");

}



