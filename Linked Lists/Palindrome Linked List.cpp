/*Method 1: Using stack
(1) Traverse the linked list and push all the nodes in the stack
(2) Now again traverse the list and pop out elements and compare with the current node
to check if it is palindrome.

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
	bool isPalindrome(ListNode* head)
	{
		ListNode* curr = head;
		stack<int> s1;

		while (curr != NULL)
		{
			s1.push(curr->val);
			curr = curr->next;
		}

		curr = head;
		while (curr != NULL)
		{
			if (curr->val == s1.top())
			{
				s1.pop();
				curr = curr->next;
			}
			else
				return false;
		}
		return true;
	}
};

/*Method 2: By reversing half of the linked list and checking for palindrome

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
	ListNode* Reverse(ListNode* head)
	{
		ListNode *curr = head, *prev = NULL, *next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
	bool isPalindrome(ListNode* head)
	{
		ListNode* curr = head;

		if (head == NULL || head->next == NULL)
			return true;
		if (head->next->next == NULL)
		{
			if (head->val == head->next->val)
				return true;
			else
				return false;
		}
		ListNode* slow = head, *fast = head;

		while (fast->next != NULL and fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *temp = Reverse(slow->next);
		while (head != NULL and temp != NULL)
		{
			if (head->val != temp->val)
				return 0;
			head = head->next;
			temp = temp->next;
		}
		return 1;
	}
};
