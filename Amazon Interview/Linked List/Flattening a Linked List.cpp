#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *down;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->down = NULL;
    }
};

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->down = merge(head1->down, head2);
    }
    else
    {
        result = head2;
        result->down = merge(head1, head2->down);
    }
    result->right = NULL;
    return result;
}


Node *flatten(Node *head)
{
    if (head == NULL or head->right == NULL)
    {
        return head;
    }
    return merge(head, flatten(head->right));
}


int main()
{
    Node *root = new Node(5);
    root->right = new Node(10);
    root->right->right = new Node(19);
    root->right->right->right = new Node(28);
    root->down = new Node(7);
    root->down->down = new Node(8);
    root->down->down->down = new Node(30);
    root->right->down = new Node(20);
    root->right->right->down = new Node(22);
    root->right->right->down->down = new Node(50);
    root->right->right->right->down = new Node(35);
    root->right->right->right->down->down = new Node(40);
    root->right->right->right->down->down->down = new Node(45);

    root = flatten(root);

    Node *temp = root;
    while (temp != NULL)
    {
        Node *temp2 = temp;
        while (temp2->down != NULL)
        {
            cout << temp2->data << " ";
            temp2 = temp2->down;
        }
        temp = temp->right;
    }
    return 0;
}