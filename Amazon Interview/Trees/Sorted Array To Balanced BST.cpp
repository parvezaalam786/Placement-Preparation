/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *createBalancedBST(const vector<int>& A, int low, int high)
{
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	TreeNode *root = new TreeNode(A[mid]);
	root->left = createBalancedBST(A, low, mid - 1);
	root->right = createBalancedBST(A, mid + 1, high);
	return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A)
{
	return createBalancedBST(A, 0, A.size() - 1);
}
