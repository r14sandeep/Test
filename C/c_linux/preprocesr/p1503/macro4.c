#define A 10
main()
{
	extern int j;
	int i=A;
	printf("%d\n",j);
#define A 20
	printf("%d\n",i);
	printf("%d\n",i+A);
#define A 30
	printf("%d\n",A);

}
#define A 40
int j=A;		

