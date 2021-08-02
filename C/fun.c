#include<stdio.h>
void call_by_val(int val)
{
     val=val+1;
}
void call_by_ref(int *ptr)
{
	printf("ref:%d\n",*ptr);
   ++*ptr;
	printf("ref:%d\n",*ptr);

}
int main()
{
    int val=5;
    call_by_val(val);
    printf("%d\n",val);
    call_by_ref(&val);
    printf("%d\n",val);

}
