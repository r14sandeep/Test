#include<stdio.h>
#include<stdlib.h>
void main()
 {
   FILE*fp;
   char ch ,fname[20];
   printf("enter the file name to be opened\n");
   scanf("%s",fname);
   fp=fopen(fname,"r");
   if(fp==NULL)
    {
      printf("file does not exit. cannot open\n");
      exit(1);
    }
   printf("file contents are\n");
   while(1)
    {
     ch=fgetc(fp);
     if(ch==EOF)
       break;
      printf("%c",ch);
    }
    fclose(fp);
 }         
      
   
   
  
