#include<stdio.h>
main(int argc,char **argv)
{
	FILE *f;
	char *buf=NULL,*found;
	int s,cnt=0;
	f=fopen(argv[1],"r");
	fseek(f,0,2);
	s=ftell(f);
	rewind(f);
	buf=calloc(1,s+1);
	fread(buf,s,1,f);
	found=buf;
	while(strstr(found,argv[2]))
	{
		cnt++;
		found++;
		printf("found at%d",found);


	}
	printf("%d\n",cnt);
}
