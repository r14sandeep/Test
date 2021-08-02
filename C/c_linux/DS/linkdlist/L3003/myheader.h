#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dll
{
	int info;
	struct dll *prev,*next;
};
