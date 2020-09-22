/*
Given a binary tree. Modify it in such a way that after modification you can have a preorder traversal of it using only the
right pointers. During modification, you can use right as well as left pointers.
Input :    10
          /   \
        8      2
      /  \
    3     5
Output :    10
              \
               8
                \
                 3
                  \
                   5
                    \
                     2
Explanation : The preorder traversal
of given binary tree is 10 8 3 5 2.
*/

#include<bits/stdc++.h>
using namespace std;

class tree
{
public:
    int data;
    tree *left, *right;

    tree()
    {
        this->left = NULL;
        this->right = NULL;
    }
    tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    tree* change(tree *root)
    {
        if (root == NULL)
            return root;

        tree *pre = NULL;
        stack<tree*> stk;

        stk.push(root);
        bool first = true;
        while (!stk.empty())
        {
            tree *curr = stk.top();
            stk.pop();
            if (curr->right)
                stk.push(curr->right);
            if (curr->left)
                stk.push(curr->left);
            if (pre != NULL)
            {
                pre->right = curr;
            }
            pre = curr;
            if (first)
            {
                root = pre;
                first = false;
            }
        }
        return root;
    }

    void print(tree *root)
    {
        while (root)
        {
            cout << root->data << " ";
            root = root->right;
        }
    }
};


int main()
{
    tree *root = new tree(10);
    root->left = new tree(8);
    root->right = new tree(2);
    root->left->left = new tree(3);
    root->left->right = new tree(5);

    root = root->change(root);

    root->print(root);

    return 0;
}