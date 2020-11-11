/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B)
{
    priority_queue<int> pq;
    stack<TreeNode*> s1;
    s1.push(A);
    while (!s1.empty())
    {
        TreeNode *curr = s1.top();
        s1.pop();
        pq.push(curr->val);
        if (pq.size() > B)
            pq.pop();
        if (curr->right)
            s1.push(curr->right);
        if (curr->left)
            s1.push(curr->left);
    }
    return pq.top();
}
