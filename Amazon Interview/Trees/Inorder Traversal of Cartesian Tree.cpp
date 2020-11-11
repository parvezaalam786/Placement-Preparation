/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *helper(vector<int>& A, int start, int end)
{
    if (start > end)
        return NULL;
    if (start == end)
        return new TreeNode(A[start]);

    int root = A[start];
    int idx = start;
    for (int i = start; i <= end; i++)
    {
        if (root < A[i])
        {
            root = A[i];
            idx = i;
        }
    }
    TreeNode *temp = new TreeNode(root);
    temp->left = helper(A, start, idx - 1);
    temp->right = helper(A, idx + 1, end);
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &A)
{
    return helper(A, 0, A.size() - 1);
}
