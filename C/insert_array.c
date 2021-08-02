#include<stdio.h>
int main()
{
	int arr[10],index1=0,index2;
	int index,val,size,choice;
	size=sizeof(arr)/sizeof(arr[0]);
	while(1)
	{
	printf("***MENU***\n");
	printf("1.insert\n2.display\n3.exit\n");
	printf("enter your choice:");
	scanf("%d",&choice);
/******inserting into array******/

	if(choice==1)
	{
		if(index1==0)
		{
			printf("enter value at index 0:");
			scanf("%d",&val);
			arr[index1++]=val;
		}
		else
		{	
			printf("enter the index from 0 to %d only\n",index1);
			scanf("%d",&index);
			printf("enter the value:");
			scanf("%d",&val);
			if(index1==index)
				arr[index1++]=val;
			else
			{
				int cnt=0,temp1,temp2;
				temp1=index1;
				temp2=index;
				while(temp2<index1)
				{
					arr[temp1]=arr[temp1-1];
					temp1--;temp2++;
				}
				arr[index]=val;
				index1++;

			}
		
		}
	}	

/******displaying array********/

	if(choice==2)
		for(index=0;index<index1;index++)
			printf("%d ",arr[index]);
	else if(choice==3)break;
	}	

}
