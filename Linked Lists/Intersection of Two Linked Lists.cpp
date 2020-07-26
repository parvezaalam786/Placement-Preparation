/**
Method: After the intersection point the lengths of the linked lists are same
So we find the diffence between the lengths and move the head of the longer
linekd list ahead by difference and the move both the heads simultaneously.
The point at which they become equal is the intersection point.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        if (head1 == head2)
            return head1;

        int cnt1 = 0, cnt2 = 0;
        while (curr1 != NULL)
        {
            cnt1++;
            curr1 = curr1 -> next;
        }
        while (curr2 != NULL)
        {
            cnt2++;
            curr2 = curr2 -> next;
        }
        curr1 = head1;
        curr2 = head2;
        int diff = abs(cnt1 - cnt2);

        if (cnt1 > cnt2)
        {
            while (diff > 0)
            {
                diff--;
                curr1 = curr1 -> next;
            }
        }
        else if (cnt2 > cnt1)
        {
            while (diff > 0)
            {
                diff--;
                curr2 = curr2 -> next;
            }
        }

        ListNode* ans = NULL;
        if (head1 == head2)
            return head1;
        while (curr1 != NULL and curr2 != NULL)
        {
            if (curr1->next == curr2->next)
            {
                ans = curr1->next;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return ans;
    }
};