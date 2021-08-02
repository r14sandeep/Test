#include"header.h"
main()
{
	NODE *head=0;
	int ch;
	while(1)
	{
		printf("1-add\n2-print\n3-del\n4-save\n");
		printf("enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add(&head);break;
			case 2:print(head);break;
			case 3:del(&head);
				//del1stnode(&head);	
				//dellastnode(&head);
				break;
			case 4:save(*head);break;
			default:printf("invalid choice\n");break;

		}

	}
}
