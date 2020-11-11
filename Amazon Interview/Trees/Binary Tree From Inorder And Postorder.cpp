/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *constructTree(vector<int>& postorder, auto &mp, int& idx, int start, int end)
{
    if (start > end)
        return NULL;
    TreeNode *root = new TreeNode(postorder[idx]);
    int i = mp[postorder[idx]];
    idx--;
    root->right = constructTree(postorder, mp, idx, i + 1, end);
    root->left = constructTree(postorder, mp, idx, start, i - 1);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    map<int, int> mp;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        mp[A[i]] = i;
    }
    int idx = n - 1;
    return constructTree(B, mp, idx, 0, n - 1);

}
