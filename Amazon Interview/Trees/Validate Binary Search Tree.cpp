/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool validate(TreeNode *root, int mn, int mx)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->val > mn and root->val < mx) and validate(root->left, mn, root->val) and
            validate(root->right, root->val, mx))
    {
        return true;
    }
    return false;
}
int Solution::isValidBST(TreeNode* A) {
    return validate(A, INT_MIN, INT_MAX);
}
