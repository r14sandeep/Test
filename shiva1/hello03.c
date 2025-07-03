#include<stdio.h>
void main()
{
  FILE*sfp,*dfp;
  char ch,sfname[20],dfname[20];
  printf("enter the file name to be opened\n");
  scanf("%s",sfname);
  printf("enter the destination file name to be opened\n");
  scanf("%s",dfname);
  sfp=fopen(sfname,"r");
  dfp=fopen(dfname,"w");
    while(1)
   {
     ch=fgetc(sfp);
     if(ch==EOF);
       break;
     fputc(ch,dfp);
   }
   fclose(sfp);
   fclose(dfp);
   printf("file copied successfully\n");
 }  
        
  
