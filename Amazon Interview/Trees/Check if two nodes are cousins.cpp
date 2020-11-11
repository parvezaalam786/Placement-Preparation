#include<bits/stdc++.h>
using namespace std;

class tree
{
public:
	tree *left, *right;
	int data;
	tree()
	{
		this->left = NULL;
		this->right = NULL;
		this->data = 0;
	}
	tree(int data)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	}

	void preorder(tree *root)
	{
		if (root == NULL)
			return ;
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

	bool isCousin(tree *root, tree *a, tree *b)
	{
		if (root == NULL)
			return false;
		tree *parA = NULL;
		tree *parB = NULL;

		queue<pair<tree*, tree*>> que;

		tree* temp = new tree(-1);

		pair<tree*, tree*> ele;

		que.push({root, temp});
		while (!que.empty())
		{
			int levelSize = que.size();

			while (levelSize--)
			{
				ele = que.front();
				que.pop();
				if (ele.first->data == a->data)
				{
					parA = ele.second;
				}
				if (ele.first->data == b->data)
				{
					parB = ele.second;
				}
				if (ele.first->left)
					que.push({ele.first->left, ele.first});
				if (ele.first->right)
					que.push({ele.first->right, ele.first});
				levelSize--;
				if (parA && parB)
					break;
			}
			if (parA && parB)
			{
				return parA != parB;
			}
			if (parA && !parB || (parB && !parA))
				return false;
		}
		return false;
	}
};

int main()
{
	tree *root = new tree(1);
	root->left = new tree(2);
	root->right = new tree(3);
	root->left->left = new tree(4);
	root->left->right = new tree(5);
	root->left->right->right = new tree(15);
	root->right->left = new tree(6);
	root->right->right = new tree(7);
	root->right->left->right = new tree(8);

	// root->preorder(root);

	tree *node1 = root->left->left;
	tree *node2 = root->right->right;

	root->isCousin(root, node1, node2) ? puts("Yes") : puts("No");
	return 0;
}



