/*
https://leetcode.com/problems/delete-nodes-and-return-forest/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Method: By postorder traversal

We call the postorder traversal from the root and will check if the root is to be deleted. If yes, then we will push the left and right childs
if they exist into our answer and then delete the root node. We will do the same for all nodes recursively.


The pointer content is passed by reference but the pointer itself is still passed by value, i.e. reassinging it to some other pointer will not be
reflected upon the exit from the method because the pointer will be set to point to the same memory block as before the call.
*/
class Solution {
public:
	vector<TreeNode*> ans;

	void Helper(TreeNode* &root, unordered_map<int, bool> &seen)
	{
		if (root == NULL)
			return;

		Helper(root->left, seen);
		Helper(root->right, seen);

		if (seen.find(root->val) != seen.end())
		{
			if (root->left)
				ans.push_back(root->left);
			if (root->right)
				ans.push_back(root->right);

			root = NULL;
			delete root;
		}
	}

	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
	{
		unordered_map<int, bool> seen;
		for (int i = 0; i < to_delete.size(); i++)
		{
			seen[to_delete[i]] = true;
		}

		Helper(root, seen);
		if (root)
		{
			ans.push_back(root);
		}
		return ans;
	}
};