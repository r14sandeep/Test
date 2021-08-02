#include"header.h"
void postorder(struct bst *node)
{
	if(node)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->info);
	}


}
