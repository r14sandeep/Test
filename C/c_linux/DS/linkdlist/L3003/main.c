#include"myheader.h"
void input(struct dll **);
void print(struct dll *);
struct dll *search(struct dll *);
void del(struct dll **);
//void reverse(struct dll **);
main()
{
	struct dll *head=NULL,*temp=NULL;
	int ch;
	while(1)
	{
		printf("****MENU****\n");
		printf("1-input\n2-print\n4-delete\n3-search\n5-reverse\n");
		printf("enter choice:");
		//getchar();
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1:input(&head);break;
			case 2:print(head);break;
			case 3:temp=search(head);
				if(temp==NULL)
					printf("not found\n");
				else
					printf("found at %u\n",temp);
				break;
	//		case 4:del(&head);break;
		case 5:reverse(&head);break;
			default:printf("invalid data\n");
				return;
		}

	}


}
