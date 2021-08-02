#include"myheader.h"
main()
{
	NODE *head=0;
	int ch;
	while(1)
	{
		printf("*****MENU*****\n");
		printf("1:add\n2:print\n3:delete\n4:sort\n5:quit\n");
		printf("enter ur choice");
		scanf("%c",&ch);
		switch(ch)
		{
			case 1:add(&head);break;
			case 2:print(head);break;
		//	case 3:del(&head);break;
		//	case 4:sort(&head);break;
			case 5:return;

		}	
		


	}


}
