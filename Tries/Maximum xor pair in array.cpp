#include<bits/stdc++.h>
using namespace std;

struct trienode
{
    trienode *left = NULL;
    trienode *right = NULL;
};
trienode *head = new trienode();

void insert(int n)
{
    trienode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int i_th_bit = ((n >> i) & 1);
        if (i_th_bit == 0)
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new trienode();
                curr = curr->left;
            }
        }
        else
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new trienode();
                curr = curr->right;
            }
        }
    }
}

int search(int arr[], int n, trienode *head)
{
    int max_xor = 0;
    trienode *curr = head;
    for (int i = 0; i < n; i++)
    {
        int curr_xor = 0;
        curr = head;
        for (int j = 31; j >= 0; j--)
        {
            int j_th_bit = ((arr[i] >> j) & 1);
            if (j_th_bit == 0)
            {
                if (curr->right)
                {
                    curr_xor += (1 << j);
                    curr = curr->right;
                }
                else
                    curr = curr->left;
            }
            else
            {
                if (curr->left)
                {
                    curr_xor += (1 << j);
                    curr = curr->left;
                }
                else
                    curr = curr->right;
            }
        }
        max_xor = max(curr_xor, max_xor);
    }
    return max_xor;
}

int main()
{
    int arr[] = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70}; //=> 127
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
        insert(arr[i]);
    cout << search(arr, n, head);
    return 0;
}