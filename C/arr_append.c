#include<stdio.h>
#include<stdlib.h>
int main()
{

   int arr1[4]={1,2,4,3},arr2[5]={0,1,5,-2,6};

   int index,size1,size2,*arr3,*inter;

    size1=sizeof(arr1)/sizeof(arr1[0]);

    size2=sizeof(arr2)/sizeof(arr2[0]);
   arr3=calloc(1,sizeof(int)*(size1+size2));
   inter=calloc(1,sizeof(int)*(size1+size2));
    for(index=0;index<size1;index++)
             arr3[index]=arr1[index];
    int index2=0,index3=0,cnt=0;
    for(;index<(size1+size2);)
	{
    	for(index2=0;index2<size1;index2++)
		if(arr1[index2]==arr2[index3])
		{
			cnt++;
			break;
		}
	if(index2==size1)
                    arr3[index++]=arr2[index3];
	index3++;
	}
printf("union is:");
    for(index2=0;index2<(index-cnt);index2++)
            printf("%d ",arr3[index2]);



cnt=0;index3=0;
   for(index=0;index<size1;index++)
    {
           for(index2=0;index2<size2;index2++)
                         if(arr1[index]==arr2[index2])
                         {               cnt++;
                                        break;
			}
                         // else
                           //             cnt++;
           if(index2!=size2)
                        inter[index3++]=arr1[index];
     }

     printf("intersection is:");
    
    for(index2=0;index2<(cnt);index2++)

            printf("%d ",inter[index2]);






}

