/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void PopulateNext(TreeLinkNode* &root)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
    {
        if (root->right != NULL)
        {
            root->left->next = root->right;
        }
        else
        {
            TreeLinkNode *parentNext = root->next, *target = NULL;
            while (parentNext != NULL)
            {
                if (parentNext->left != NULL)
                {
                    target = parentNext->left;
                }
                else if (parentNext->right != NULL)
                {
                    target = parentNext->right;
                }
                if (target != NULL)
                    break;
                parentNext = parentNext->next;
            }
            root->left->next = target;
        }
    }
    if (root->right != NULL)
    {
        TreeLinkNode *parentNext = root->next, *target = NULL;
        while (parentNext != NULL)
        {
            if (parentNext->left != NULL)
            {
                target = parentNext->left;
            }
            else if (parentNext->right != NULL)
            {
                target = parentNext->right;
            }
            if (target != NULL)
                break;
            parentNext = parentNext->next;
        }
        root->right->next = target;
    }
    PopulateNext(root->right);
    PopulateNext(root->left);
}


void Solution::connect(TreeLinkNode* A)
{
    PopulateNext(A);
}