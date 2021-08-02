#include<iostream>
using namespace std;
class node
{
	private:int data,key;
	friend class bt;
};
class bt
{
	private:node *root;
	int find(int key);

};
int bt::find(int key)
{
	if(root->key==key)
	{
		return root->data;
	}
	else
	{
		
		
	}

}
main()
{
	node aa;
	aa.find(10);

}
