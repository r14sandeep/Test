#include"header.h"
void insert(struct bst **node,int data)
{
	struct bst *nu;
	if(*node==NULL)
	{
		nu=malloc(sizeof(struct bst));
		nu->info=data;
		nu->left=NULL;
		nu->right=NULL;                    
		*node=nu;

	}
	else
	{
		if(data<(*node)->info)
		insert(&(*node)->left,data);
		else if(data>(*node)->info)
			insert(&(*node)->right,data);

	}


}
