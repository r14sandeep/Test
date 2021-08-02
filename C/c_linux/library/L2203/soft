#include<stdio.h>
#include<stdlib.h>
int main()
{
char **p=NULL,str[1][5]="abc";
 *p = malloc(8);
	*p=str;
//    *p = "100";
//	p=str;	
     
    // deallocated the space allocated to p
    free(p);
     
    // core dump/segmentation fault
    //  as now this statement is illegal
//    *p = 110;
printf("%s\n",p);     
    return 0;


}
