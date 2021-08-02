#define A 10
main()
{
	extern int j;
	int i=A;
	printf("%d\n",j);
#undef A
	printf("%d\n",i);
	printf("%d\n",i+A);//leads to syntax error
#undef A
#define A
	printf("%d\n",A);//A is replaced,but with none

}
#undef A
#define A 40
int j=A;		
//no preprocessing errors
