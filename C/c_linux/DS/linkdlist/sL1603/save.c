#include"header.h"
void save(NODE *head)
{
	FILE *fp;
	fp=fopen("stdata","w");
	while(head)
	{
		fwrite(head,sizeof(NODE)-sizeof(NODE *),1,fp);
		head=head->next;
	}
	fclose(fp);

}
