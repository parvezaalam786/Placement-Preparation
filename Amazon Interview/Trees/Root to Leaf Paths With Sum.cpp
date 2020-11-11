/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void fun(TreeNode *root, int &sum, vector<int>& temp, vector<vector<int>>& ans, int target)
{
    if (root == NULL)
        return;
    sum += root->val;
    temp.push_back(root->val);

    if (root->left == NULL and root->right == NULL and sum == target)
    {
        ans.push_back(temp);
    }
    fun(root->left, sum, temp, ans, target);
    fun(root->right, sum, temp, ans, target);

    temp.pop_back();
    sum -= root->val;
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    fun(A, sum, temp, ans, B);
    return ans;
}
