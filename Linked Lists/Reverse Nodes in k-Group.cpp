/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of
nodes is not a multiple of k then left - out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

Recursive:

/**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int cnt = 0;
        ListNode *temp = head;
        while (temp != NULL and cnt < k)
        {
            temp = temp->next;
            cnt++;
        }
        if (cnt < k)
            return head;
        else
            cnt = 0;
        while (curr != NULL and cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if (curr != NULL)
        {
            ListNode *res = reverseKGroup(curr, k);
            head->next = res;
        }
        return prev;
    }
};