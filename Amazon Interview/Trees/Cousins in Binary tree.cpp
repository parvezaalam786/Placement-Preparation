/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findLevel(TreeNode *root, int target, int level, int &ans)
{
    if (root == NULL)
        return;
    if (root->val == target)
    {
        ans = level;
        return;
    }
    findLevel(root->left, target, level + 1, ans);
    findLevel(root->right, target, level + 1, ans);
    return;
}

vector<int> Solution::solve(TreeNode* A, int B)
{
    vector<int> ans;
    int targetlevel = 0;
    findLevel(A, B, 1, targetlevel);
    if (targetlevel == 1)
        return ans;
    queue<TreeNode*> que;
    que.push(A);
    int currlevel = 1;
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = que.front();
            que.pop();
            if (curr->left and curr->left->val == B)
                continue;
            else if (curr->right and curr->right->val == B)
                continue;
            else
            {
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }
        }
        if (currlevel + 1 == targetlevel)
            break;
        currlevel++;
    }
    while (!que.empty())
    {
        ans.push_back(que.front()->val);
        que.pop();
    }
    return ans;
}
