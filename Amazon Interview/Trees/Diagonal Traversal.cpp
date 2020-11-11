/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void DiagonalTraversal(TreeNode *root, map<int, vector<int>>& mp, int curr_diagonal)
{
    if (root == NULL)
        return;
    mp[curr_diagonal].push_back(root->val);
    DiagonalTraversal(root->left, mp, curr_diagonal + 1);
    DiagonalTraversal(root->right, mp, curr_diagonal);
    return;
}

vector<int> Solution::solve(TreeNode* A)
{
    map<int, vector<int>> mp;
    vector<int> diagonalTraversal;

    DiagonalTraversal(A, mp, 0);
    for (auto &x : mp)
    {
        diagonalTraversal.insert(diagonalTraversal.end(), x.second.begin(), x.second.end());
    }
    return diagonalTraversal;

}
