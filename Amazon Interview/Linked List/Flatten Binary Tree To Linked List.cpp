/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode *curr = A, *prev = A;
    stack<TreeNode*> s1;
    while (curr != NULL)
    {
        if (curr->right)
        {
            s1.push(curr->right);
        }
        curr = curr->left;
        if (curr == NULL and s1.size() > 0)
        {
            curr = s1.top();
            s1.pop();
        }
        prev->left = NULL;
        prev->right = curr;
        prev = prev->right;
    }
    return A;
}
