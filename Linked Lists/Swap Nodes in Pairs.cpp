/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

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
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL or head->next == NULL)
			return head;
		ListNode *curr = head, *prev = NULL;

		while (curr != NULL and curr->next != NULL)
		{
			ListNode *temp = curr->next;
			curr->next = temp->next;
			temp->next = curr;

			if (prev == NULL)
			{
				head = temp;
				prev = temp;
			}
			else
				prev->next = temp;

			prev = curr;
			curr = curr->next;
		}

		return head;
	}
};