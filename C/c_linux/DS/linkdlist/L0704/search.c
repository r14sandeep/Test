#include"header.h"
struct bst*search(struct bst *node,int data)
{
	if(node==NULL)
		return NULL;
	else
		if(data<node->info)
		return (search(node->left,data));
		else if(data>node->info)
		return (search(node->right,data));
		else 
			return (node);

	


}
