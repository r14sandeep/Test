 #include<stdio.h>

struct student{
    int roll;
//    char name[100];
    float marks;
};

int main(){

 // struct student *ptr=NULL;
	int *ptr=0,a=1;
	ptr=&a;
	ptr++;
printf("Size of the structure student:  %d\n",ptr);
	 
// ptr++;
printf("Size of the structure student:  %d\n",*ptr);

  return 0;
}
