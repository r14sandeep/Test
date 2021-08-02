#include<stdio.h>
int main()
{
      FILE *fp;
      fp=fopen("file.txt","r");
      char line[200],word[200];
      int line_cnt=0,word_cnt=0,size;
      while(fgets(line,200,fp))
                   line_cnt++;
       rewind(fp);
       while(fscanf(fp,"%s",word)!=EOF)
                     word_cnt++;
        fseek(fp,0,2);
        size=ftell(fp);
        printf("lines=%d,words=%d,chars=%d\n",line_cnt,word_cnt,size);
}
