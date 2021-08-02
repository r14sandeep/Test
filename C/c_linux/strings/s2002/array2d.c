#include<stdio.h>
main()
{
	double d[4][3]={{1.1,2.2},{3.3},{4.4},{5.5,6.6}};
	int rows,cols,i,j;
	rows=sizeof(d)/sizeof(d[0]);
	cols=sizeof(d[0])/sizeof(d[0][0]);
	for(i=0;i<rows;i++,printf("\n"))
		for(j=0;j<cols;j++)
			printf("%.2lf ",d[i][j]);
		

}
