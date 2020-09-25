#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    else if (root->data < x)
        root->right = insert(root->right, x);
    else if (root->data > x)
        root->left = insert(root->left, x);
    return root;
}

Node *getSuccessor(Node *root)
{
    root = root->right;
    while (root != NULL and root->left != NULL)
        root = root->left;
    return root;
}

Node *delNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right, succ->data);
        }
    }
    return root;
}



int main()
{
    Node *root = new Node(50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 10);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    preorder(root);
    cout << "\n";
    delNode(root, 50);
    preorder(root);
    return 0;
}