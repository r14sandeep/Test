#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sensor
{
	struct acc
	{
		char buf[100];
		float x,y,z;
	}ACC;
	struct mag
	{
		char buf[100];
		float x,y,z;
	};
	struct ori
	{
		char buf[100];
		float x,y,z;
	}ORI;


}SENSOR;

