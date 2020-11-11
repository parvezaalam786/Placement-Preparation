/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    vector<vector<int>> ans;
    stack<TreeNode*> s1, s2;
    s1.push(A);
    bool is_reverse = false;
    while (!s1.empty())
    {
        vector<int> temp;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = s1.top();
            s1.pop();
            temp.push_back(curr->val);
            if (is_reverse)
            {
                if (curr->right)
                    s2.push(curr->right);
                if (curr->left)
                    s2.push(curr->left);
            }
            else
            {
                if (curr->left)
                    s2.push(curr->left);
                if (curr->right)
                    s2.push(curr->right);
            }
        }
        ans.push_back(temp);
        swap(s1, s2);
        is_reverse = !is_reverse;
    }
    return ans;
}
