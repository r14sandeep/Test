#include"header.h"
void inorder(struct bst *node)
{
	if(node)
	{
		inorder(node->left);
		printf("%d ",node->info);
		inorder(node->right);
	}

}
