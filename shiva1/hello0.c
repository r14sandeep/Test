#include<stdio.h>
#include<stdlib.h>
void main()
 {
   FILE*fp;
   char ch,fname[20],name[20];
   int rno,age;
   printf("enter the filename to be opened\n");
   scanf("%s",fname);
   fp=fopen(fname,"w");
   printf("enter name ,rno and age\n");
   scanf("%s%d%d",name,&rno,&age);
    
    /*writing data to the file*/
   
   fprintf(fp,"name is %s\n",name);
   fprintf(fp,"roll number is%d\n",rno);
   fprintf(fp,"age is %d\n",age);
   
   fclose(fp); 
 }   
