/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A)
{
    vector<int> Preorder;
    TreeNode *curr;
    stack<TreeNode*> s1;
    s1.push(A);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        Preorder.push_back(curr->val);
        if (curr->right)
            s1.push(curr->right);
        if (curr->left)
            s1.push(curr->left);
    }
    return Preorder;
}
