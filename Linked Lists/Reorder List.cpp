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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;
        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head)
    {
        if (head == NULL or head->next == NULL)
            return;

        ListNode *slow = head, *fast = head, *prev = NULL;

        while (fast != NULL and fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = NULL;

        if (fast == NULL)
        {
            head2 = slow;
            prev->next = NULL;
        }
        else
        {
            head2 = slow->next;
            slow->next = NULL;
        }
        head2 = reverse(head2);

        ListNode *head1 = head;

        head = new ListNode(0);
        ListNode *temp = head;
        while (head1 or head2)
        {
            if (head1)
            {
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            if (head2)
            {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        head = head->next;
    }
};