/*
Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S
consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire
tree; the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T.
Tree S
          10
        /    \
      4       6
       \
        30
Tree T
              26
            /   \
          10     3
        /    \     \
      4       6     3
       \
        30

There are two methods of doing it:
Method1: O(mn)
Traverse the tree T in preorder fashion. For every visited node in the traversal, see if the subtree rooted with this
node is identical to S.

Method2: O(n)
i) Find inorder of tree T(say inorderT) and tree S(say inorderS)
ii) Find preorder of tree T(say preorderT) and tree S(say preorderS)

if((inorderS is subarray of inorderT) == true and (preorderS is subarray of preorderT) == true)
    return true;
else
    return false;
*/

#include<bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;

    treenode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/**************** Method 1 ****************/
bool areIdentical(treenode *root1, treenode *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    if (root1 == NULL or root2 == NULL)
        return false;
    return (root1->data == root2->data && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
}

bool isSubtree1(treenode *T, treenode *S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;

    if (areIdentical(T, S))
        return true;

    return isSubtree1(T->left, S) or isSubtree1(T->right, S);
}

/***************** Method 2 *****************/

void Inorder(treenode *root, vector<char>& arr)
{
    if (root == NULL)
    {
        arr.push_back('$');
        return;
    }
    Inorder(root->left, arr);
    arr.push_back(root->data + '0');
    Inorder(root->right, arr);
}

void Preorder(treenode *root, vector<char>& arr)
{
    if (root == NULL)
    {
        arr.push_back('$');
        return;
    }
    arr.push_back(root->data + '0');
    Preorder(root->left, arr);
    Preorder(root->right, arr);
}

bool isSubtree2(treenode *T, treenode *S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;

    vector<char> preT, preS;
    Preorder(T, preT);
    Preorder(S, preS);
    preT.push_back('\0');
    preS.push_back('\0');

    char temp1[500], temp2[500];
    for (int i = 0; i < preT.size(); i++)
        temp1[i] = preT[i];
    for (int i = 0; i < preS.size(); i++)
        temp2[i] = preS[i];

    if (strstr(temp1, temp2) == NULL)
        return false;

    vector<char> inT, inS;
    Inorder(T, inT);
    Inorder(S, inS);
    inT.push_back('\0');
    inS.push_back('\0');

    char temp3[500], temp4[500];

    for (int i = 0; i < preT.size(); i++)
        temp3[i] = inT[i];
    for (int i = 0; i < preS.size(); i++)
        temp4[i] = inS[i];

    return (strstr(temp3, temp4) != NULL);
}




int main()
{
    treenode *T = new treenode(26);
    T->right = new treenode(3);
    T->right->right = new treenode(3);
    T->left = new treenode(10);
    T->left->left = new treenode(4);
    T->left->left->right = new treenode(30);
    T->left->right = new treenode(6);

    treenode *S = new treenode(10);
    S->right = new treenode(6);
    S->left = new treenode(4);
    S->left->right = new treenode(30);

    if (isSubtree1(T, S))
        cout << "Tree S is subtree of tree T by method 1\n";
    else
        cout << "Tree S is not subtree of tree T by method 1\n";


    if (isSubtree2(T, S))
        cout << "Tree S is subtree of tree T by method 2\n";
    else
        cout << "Tree S is not subtree of tree T by method 2\n";

    return 0;
}



