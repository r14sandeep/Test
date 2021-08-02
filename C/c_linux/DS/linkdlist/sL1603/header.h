#include<stdio.h>
#include<stdlib.h>
typedef struct tag
{
	int roll;
	char name[20];
	float mark;
	struct tag *next;
}NODE;

