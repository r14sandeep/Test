 #include<stdio.h>
int** ibm(){
    static int a[]={4,8,12,16};
    static int *pointer=a;
    static int **p=&pointer;
    return p;
}
int main(){
    int **ptr;
    ptr=ibm();
    printf("%d",++**ptr);
    return 0;        
}
