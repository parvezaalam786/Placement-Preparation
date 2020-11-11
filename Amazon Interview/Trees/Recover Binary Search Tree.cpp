/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Method:1 Using o(n) space*/
vector<int> Solution::recoverTree(TreeNode* A)
{
    vector<int> inorder;
    TreeNode *curr = A;

    stack<TreeNode*> s1;
    while (curr != NULL || s1.empty() == false)
    {
        while (curr)
        {
            s1.push(curr);
            curr = curr->left;
        }
        curr = s1.top();
        s1.pop();
        inorder.push_back(curr->val);
        curr = curr->right;
    }
    vector<int> temp(inorder);
    sort(temp.begin(), temp.end());
    vector<int> ans;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (temp[i] != inorder[i])
            ans.push_back(temp[i]);
    }

    return ans;
}

/*Using Morris Inoreder Traversal in O(n) time complexity and O(1) space complexity*/
vector<int> Solution::recoverTree(TreeNode* root)
{
    TreeNode *prev = NULL, *first = NULL, *second = NULL, *curr;
    curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            if (prev != NULL)
            {
                if (prev->val > curr->val)
                {
                    if (first == NULL)
                    {
                        first = prev;
                    }
                    second = curr;
                }
            }
            prev = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode *predecessor = curr->left;
            while (predecessor->right != curr and predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                if (prev != NULL)
                {
                    if (prev->val > curr->val)
                    {
                        if (first == NULL)
                        {
                            first = prev;
                        }
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    vector<int> ans = {first->val, second->val};
    if (ans[0] > ans[1])
        swap(ans[0], ans[1]);
    return ans;
}
