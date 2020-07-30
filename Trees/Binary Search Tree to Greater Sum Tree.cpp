// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
	We will do reverse inorder traversal with liitle modification

	root -> operation on root -> left
*/

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void go(Node *root, int *sum)
{
	if (root)
	{
		go(root->right, sum);
		*sum = *sum + root->data;
		root->data = *sum ;
		go(root->left, sum);
	}
}

void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << (root->data) << " ";
		inorder(root->right);
	}

}
void solve()
{
	Node *root = new Node(11);
	root->left = new Node(2);
	root->right = new Node(29);
	root->left->left = new Node(1);
	root->left->right = new Node(7);
	root->right->left = new Node(15);
	root->right->right = new Node(40);
	root->right->right->left = new Node(35);

	int sum = 0;
	go(root, &sum);
	inorder(root);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
