/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> s1;

BSTIterator::BSTIterator(TreeNode *root)
{
    while (!s1.empty())
    {
        s1.pop();
    }
    TreeNode *curr = root;
    while (curr != NULL)
    {
        s1.push(curr);
        curr = curr->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
    return !s1.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if (s1.empty())
        return -1;
    int ans = s1.top()->val;
    TreeNode *curr = s1.top();
    s1.pop();
    curr = curr->right;
    while (curr != NULL)
    {
        s1.push(curr);
        curr = curr->left;
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
