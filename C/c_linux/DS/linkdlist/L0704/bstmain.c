#include"header.h"
main()
{
	struct bst *root=NULL,*temp=NULL;
	int ch,data;
	while(1)
	{
		printf("\n1-insert\n2-preorder\n3-postorder\n4-inorder\n5-search\n6-delete\n");
	printf("enter ur choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter data:");
			scanf("%d",&data);
			insert(&root,data);break;
		case 2:preorder(root);break;
		case 3:postorder(root);break;
		case 4:inorder(root);break;
		case 5:printf("enter data to be searchd:");
			scanf("%d",&data);
			temp=search(root,data);
			if(temp==NULL)
				printf("not found\n");
			else
				printf("found %d\n",temp->info);
			break;
	//	case 6:printf("enter data );
		case 7:exit(0);
		default:printf("invalid choice\n");break;
	}

	}


}
