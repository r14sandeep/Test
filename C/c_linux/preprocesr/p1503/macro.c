#define f1(v) v
#define f2(v) "v"
#define f3(v) #v
#define f4(a,b) a##b
main()
{
	f1(vector);
	f1(12);
	f2(vector);
	f2(12);

	f3(vector);
	f3(12);
	f4(12,34);

	f4(vector,embedded);
}



