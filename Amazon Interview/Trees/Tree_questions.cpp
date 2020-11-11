#include<bits/stdc++.h>
using namespace std;
/*
Note:
(i) Inorder traversal in case of BST always gives sorted array
*/
class tree
{
private:

public:
	int value;
	tree *left, *right;
	tree(int value)
	{
		this->value = value;
		this->left = this->right = NULL;
	}

	tree* insert(int value, tree *root)
	{
		if (root == NULL)
			return new tree(value);
		if (value < root->value)
			root->left = insert(value, root->left);
		else
			root->right = insert(value, root->right);
		return root;
	}

	void inorder(tree* root)
	{
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}

	void preorder(tree *root)
	{
		if (root == NULL)
			return;
		cout << root->value << " ";
		preorder(root->left);
		preorder(root->right);
	}

	void postorder(tree* root)
	{
		if (root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->value << " ";
	}

	void  level_order_traversal(tree* root)
	{
		queue<tree*> que;
		que.push(root);
		while (!que.empty())
		{
			tree* temp = que.front();
			que.pop();
			cout << temp->value << " ";
			if (temp->left)
				que.push(temp->left);
			if (temp->right)
				que.push(temp->right);
		}
	}

	void left_view(tree* root)
	{
		queue<tree*> que;
		que.push(root);
		while (!que.empty())
		{
			int n = que.size();
			for (int i = 1; i <= n; i++)
			{
				tree *temp = que.front();
				que.pop();
				if (i == 1)
					cout << temp->value << " ";
				if (temp->left)
					que.push(temp->left);
				if (temp->right)
					que.push(temp->right);
			}
		}
	}

	void right_view(tree* root)
	{
		queue<tree*> que;
		que.push(root);
		while (!que.empty())
		{
			int n = que.size();
			for (int i = 1; i <= n; i++)
			{
				tree *temp = que.front();
				que.pop();
				if (i == n)
					cout << temp->value << " ";
				if (temp->left)
					que.push(temp->left);
				if (temp->right)
					que.push(temp->right);
			}
		}
	}

	void top_view(tree* root)
	{
		map<int, int> m1;
		queue<pair<tree*, int>> que;
		que.push({root, 0});

		while (!que.empty())
		{
			auto temp = que.front();
			que.pop();
			int hd = temp.second;
			if (m1.count(hd) == 0)
			{
				m1[hd] = temp.first->value;
			}
			if (temp.first->left)
				que.push({temp.first->left, hd - 1});
			if (temp.first->right)
				que.push({temp.first->right, hd + 1});
		}
		for (auto i : m1)
			cout << i.second << " ";
		cout << "\n";
	}

	void bottom_view(tree* root)
	{
		map<int, int> m1;
		queue<pair<tree*, int>> que;
		que.push({root, 0});

		while (!que.empty())
		{
			auto temp = que.front();
			que.pop();
			int hd = temp.second;

			m1[hd] = temp.first->value;

			if (temp.first->left)
				que.push({temp.first->left, hd - 1});
			if (temp.first->right)
				que.push({temp.first->right, hd + 1});
		}
		for (auto i : m1)
			cout << i.second << " ";
		cout << "\n";
	}
	int get_tree_height(tree *root)
	{
		if (root == NULL)
			return 0;
		int left = get_tree_height(root->left);
		int right = get_tree_height(root->right);

		return max(left, right) + 1;
	}

	tree* array_to_bst(int arr[], int start, int end)
	{
		/*
		    Since the array is sorted, we will always divide the array from middle to create the bst.
		*/
		if (start > end)
			return NULL;
		int middle = (start + end) / 2;
		tree *root = new tree(arr[middle]);
		root->left = array_to_bst(arr, start, middle - 1);
		root->right = array_to_bst(arr, middle + 1, end);
		return root;
	}

	tree* create_tree_preorder_inorder(int &pre_idx, int start, int end, int pre[], unordered_map<int, int>& mp)
	{
		if (start > end)
			return NULL;
		tree *root = new tree(pre[pre_idx]);
		int idx = mp[pre[pre_idx]];
		pre_idx++;
		root->left = create_tree_preorder_inorder(pre_idx, start, idx - 1, pre, mp);
		root->right = create_tree_preorder_inorder(pre_idx, idx + 1, end, pre, mp);
		return root;
	}

	tree *create_tree_postorder_inorder(int &pos_idx, int start, int end, int pos[], unordered_map<int, int>& mp)
	{
		if (start > end)
			return NULL;
		tree *root = new tree(pos[pos_idx]);
		int idx = mp[pos[pos_idx]];
		pos_idx--;
		root->right = create_tree_postorder_inorder(pos_idx, idx + 1, end, pos, mp);
		root->left = create_tree_postorder_inorder(pos_idx, start, idx - 1, pos, mp);
		return root;
	}

	bool is_identical_trees(tree *root1, tree *root2)
	{
		//Both trees are NULL
		if (root1 == NULL and root2 == NULL)
			return true;
		// one tree is empty and one is not empty
		if (root1 == NULL or root2 == NULL)
			return false;

		if (root1->value != root2->value)
			return false;

		return is_identical_trees(root1->left, root2->left) and
		       is_identical_trees(root1->right, root2->right);

	}

	bool is_mirror_tree(tree *root1, tree *root2)
	{
		//Both trees are NULL
		if (root1 == NULL and root2 == NULL)
			return true;
		// one tree is empty and one is not empty
		if (root1 == NULL or root2 == NULL)
			return false;

		if (root1->value != root2->value)
			return false;

		return is_identical_trees(root1->left, root2->right) and
		       is_identical_trees(root1->right, root2->left);
	}

	void serialize_tree(tree* root, FILE *fp)
	{
		/* (i) in case of bst just do preorder traversal and for inorder traversal sort the preorder and now we have preorder and inorder traversal and can construct the tree.
		   (ii) in case of binary tree we will store the preorder traversal and in place of null values we will store -1
		*/
		if (root == NULL)
		{
			fprintf(fp, "%d ", -1);
			return;
		}
		fprintf(fp, "%d ", root->value);
		serialize_tree(root->left, fp);
		serialize_tree(root->right, fp);
	}

	tree* deserialize(FILE *fp)
	{
		// we will create the binary tree in the preorder fashion
		int value;
		if (!fscanf(fp, "%d", &value) or value == -1)
			return NULL;
		tree *root = new tree(value);
		root->left = deserialize(fp);
		root->right = deserialize(fp);
		return root;
	}

	void binary_tree_to_dll(tree *root, tree* &head, tree* &prev)
	{
		/*
		    we will create the doubly linked list by maintaining a prev pointer which is basically the previous node in the linked list
		    formed by inorder traversal.
		    We will point the left of currrent node to prev and right of prev to current node.
		    For creating the dll to circular dll make the head->right point to last node and last node right point to head
		*/

		if (!root)
			return;
		binary_tree_to_dll(root->left, head, prev);
		if (prev == NULL)
		{
			head = root;
		}
		else
		{
			root->left = prev;
			prev->right = root;
		}
		prev = root;
		binary_tree_to_dll(root->right, head, prev);
	}

	bool printAncestors(tree *root, int node)
	{
		if (root == NULL)
			return false;
		if (root->value == node)
			return true;
		if (printAncestors(root->left, node) || printAncestors(root->right, node))
		{
			cout << root->value << " ";
			return true;
		}
		return false;
	}

};


int main()
{
	/*
	                  7
	                /   \
	               5     8
	              /  \    \
	             4   6     9
	*/

	// tree *root = NULL;
	// root = root->insert(7, root);
	// root = root->insert(5, root);
	// root = root->insert(8, root);
	// root = root->insert(4, root);
	// root = root->insert(6, root);
	// root = root->insert(9, root);

	// root->inorder(root);
	// cout << "\n";
	// root->preorder(root);
	// cout << "\n";
	// root->postorder(root);
	// cout << "\n";
	// root->level_order_traversal(root);
	// cout << "\n";

	// root->left_view(root);
	// root->right_view(root);

	// root->top_view(root);
	// root->bottom_view(root);

	// cout << root->get_tree_height(root);

	// int arr[] = {1, 2, 3, 4, 5};
	// tree *root1 = NULL;
	// root1 = root1->array_to_bst(arr, 0, 4);
	// root1->inorder(root1);
	// root1->preorder(root1);

	// int in[] = {3, 1, 4, 0, 5, 2};
	// int pre[] = {0, 1, 3, 4, 2, 5};
	// unordered_map<int, int>  mp;
	// for (int i = 0; i < 6; i++)
	// {
	//     mp[in[i]] = i; // storing the values occuring at which index
	// }
	// int pre_idx = 0;
	// tree *root2 = NULL;
	// root2 = root2->create_tree_preorder_inorder(pre_idx, 0, 5, pre, mp);
	// root2->preorder(root2);
	// root2->inorder(root2);

	int in[] = {3, 12, 6, 4, 7, 10, 11, 5, 2, 8};
	int pos[] = {3, 6, 7, 4, 12, 11, 8, 2, 5, 10};
	unordered_map<int, int> mp;
	int n = 10;
	for (int i = 0; i < n; i++)
		mp[in[i]] = i;
	int pos_idx = n - 1;
	tree *root = NULL;
	root = root->create_tree_postorder_inorder(pos_idx, 0, n - 1, pos, mp);
	root->preorder(root);

	// tree *root3 = NULL, *root4 = NULL;
	// root3 = root3->insert(7, root3);
	// root3 = root3->insert(2, root3);
	// root3 = root3->insert(8, root3);
	// root3 = root3->insert(1, root3);
	// root3 = root3->insert(5, root3);

	// root4 = root4->insert(7, root4);
	// root4 = root4->insert(2, root4);
	// root4 = root4->insert(8, root4);
	// root4 = root4->insert(1, root4);
	// root4 = root4->insert(5, root4);
	// cout << root3->is_identical_trees(root3, root4);
	// cout << root5->is_mirror_tree(root3, root4);

	// tree *root6 = NULL;
	// root6 = root6->insert(7, root6);
	// root6 = root6->insert(2, root6);
	// root6 = root6->insert(8, root6);
	// root6 = root6->insert(1, root6);
	// root6 = root6->insert(5, root6);
	// // root6->preorder(root6);
	// FILE *fp = fopen("serialize_deserialize.txt", "w");
	// root6->serialize_tree(root6, fp);
	// fclose(fp);

	// fp = fopen("serialize_deserialize.txt", "r");
	// tree *root7 = NULL;
	// root7 = root7->deserialize(fp);
	// root7->inorder(root7);
	// cout << "\n";
	// root7->preorder(root7);

	// tree *root7 = NULL;
	// root7 = root7->insert(7, root7);
	// root7 = root7->insert(2, root7);
	// root7 = root7->insert(8, root7);
	// root7 = root7->insert(1, root7);
	// root7 = root7->insert(5, root7);

	// tree *head = NULL, *prev = NULL;
	// root7->binary_tree_to_dll(root7, head, prev);

	// tree *temp = head;
	// while (temp != NULL)  //we can print the doubly linked list with the help of right pointers only as they are holding the next node and left pointer holds the previous node
	// {
	//     cout << temp->value << " ";
	//     temp = temp->right;
	// }


	// tree *root8 = NULL;
	// root8 = root8->insert(7, root8);
	// root8 = root8->insert(5, root8);
	// root8 = root8->insert(8, root8);
	// root8 = root8->insert(4, root8);
	// root8 = root8->insert(6, root8);
	// root8 = root8->insert(9, root8);

	// root8->printAncestors(root8, 6);

	return 0;
}