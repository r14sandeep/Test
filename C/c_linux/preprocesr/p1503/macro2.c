#define F(x,y,z) #x "y" "vector" #y z #z x
main()
{
	F(a,b,c);
	F(int,char,float);
	F(11,12,13);



}
