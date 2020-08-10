#include<bits/stdc++.h>
using namespace std;

class Tree
{
public:
	int data;
	Tree *left, *right;
};

Tree *create(Tree *root)
{
	int x;
	cin >> x;
	if (x == -1)
		return NULL;
	root = new Tree;
	root->data = x;

	root->left = create(root->left);
	root->right = create(root->right);
	return root;
}

void inorder(Tree *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

int main()
{
	Tree *root = NULL;
	root = create(root);
	inorder(root);
	return 0;
}

/*
1
2
-1
-1
3
-1
-1

2 1 3
*/