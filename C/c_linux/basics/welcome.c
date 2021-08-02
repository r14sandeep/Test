#include<stdio.h>
before()
{
printf("before main\n");
}
main()
{
printf("print output\n");
after();

}
after()
{
printf("after main\n");
before();
}
