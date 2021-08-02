#include"header.h"
struct bst *findmin(struct bst *);
struct bst *del(struct bst *node,int data)
{
	struct bst *temp=NULL;
	if(node==NULL)
		printf("node not found\n")
	else
		if(data<node->info)
			node->left=del(node->left,data);
		else
			if(data>node->info)
				node->right=del(node->right,data);
			else
			{
				if(node->left&&node->right)
				{
					temp=findmin(node->right);
					node->info=temp->info;
					node->right=del(node->right,temp->info);

				}
				else
				{
					temp=node;
					if(node->left==NULL)
						node=node->right;
					else if(node->right==NULL)
						node=node->left;
					free(temp);
					temp=NULL;
				}

			}
return node;
}
struct bst *findmin(struct bst *node)
{
	if(node==NULL)
		return NULL;
	if(node->left)
		return findmin(node->left);
	else return node;

}
