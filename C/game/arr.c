#include<stdio.h>
int main()
{
      char ch;
  do{
 
        ch=getchar();
	printf("%d\n",ch);
        if(ch!='\0')
        {
//          ch=getchar();
          if(ch=='A')
              printf("UP\n");
                 else    if(ch=='B')
              printf("DOWN\n");
                   else    if(ch=='C')
              printf("RIGHT\n");
                     else   if(ch=='D')
              printf("LEFT\n");
        }
  }while(ch!='e');

	ch=getchar();
	printf("%d\n",ch);
    return 0;
}
