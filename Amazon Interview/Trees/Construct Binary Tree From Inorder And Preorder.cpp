/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *construct(vector<int>& A, auto &mp, int &idx, int start, int end)
{
    if (start > end)
        return NULL;
    TreeNode *root = new TreeNode(A[idx]);
    int i = mp[A[idx]];
    idx++;
    root->left = construct(A, mp, idx, start, i - 1);
    root->right = construct(A, mp, idx, i + 1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    map<int, int> mp;
    int n = B.size();
    for (int i = 0; i < n; i++)
    {
        mp[B[i]] = i;
    }
    int idx = 0;
    return construct(A, mp, idx, 0, n - 1);

}
