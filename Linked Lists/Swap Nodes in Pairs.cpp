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

//Recurive
class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL or head->next == NULL)
			return head;
		ListNode *prev = head;
		ListNode *curr = head->next;
		ListNode *next = curr->next;

		curr->next = prev;

		prev->next = swapPairs(next);
		return curr;
	}
}

//Iterative
class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL or head->next == NULL)
			return head;
		ListNode *curr = head;
		head = head->next;

		while (1)
		{
			ListNode *temp = curr->next;
			ListNode *next = temp->next;
			temp->next = curr;
			if (next == NULL or next->next == NULL)
			{
				curr->next = next;
				break;
			}
			curr->next = next->next;
			curr = next;
		}

		return head;
	}
};

