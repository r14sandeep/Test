#include"header.h"
void preorder(struct bst *node)
{
	if(node)
	{
		printf("%d ",node->info);
		preorder(node->left);
		preorder(node->right);
	}


}
