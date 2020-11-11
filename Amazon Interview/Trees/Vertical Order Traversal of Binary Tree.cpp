/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> que;
    que.push({root, 0});

    while (!que.empty())
    {
        auto curr = que.front();
        que.pop();

        mp[curr.second].push_back(curr.first->val);

        if (curr.first->left)
            que.push({curr.first->left, curr.second - 1});
        if (curr.first->right)
            que.push({curr.first->right, curr.second + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

