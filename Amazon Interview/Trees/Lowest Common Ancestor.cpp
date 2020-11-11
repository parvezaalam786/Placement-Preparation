/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check(TreeNode *root, int node)
{
    if (root == NULL)
        return false;
    if (root->val == node)
        return true;
    if (check(root->left, node) || check(root->right, node))
        return true;
    return false;
}

TreeNode *LCA(TreeNode *root, int node1, int node2)
{
    if (root == NULL)
        return NULL;

    if (root->val == node1 or root->val == node2)
        return root;

    TreeNode *lca1 = LCA(root->left, node1, node2);
    TreeNode *lca2 = LCA(root->right, node1, node2);

    if (lca1 != NULL & lca2 != NULL)
        return root;
    return lca1 ? lca1 : lca2;
}

int Solution::lca(TreeNode* A, int B, int C)
{
    if (A == NULL or check(A, B) == false or check(A, C) == false)
        return -1;

    TreeNode *ans = LCA(A, B, C);
    return ans->val;

}

