/*Given a linked list, remove the n - th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass ?

Method1 :

Approach 1 : Two pass algorithm
Intuition

We notice that the problem could be simply reduced to another one :
Remove the (L - n + 1)(L−n + 1) th node from the beginning in the list ,
where LL is the list length. This problem is easy to solve once we found list length LL.

Algorithm

First we will add an auxiliary "dummy" node, which points to the list head.
The "dummy" node is used to simplify some corner cases such as a list with only
one node, or removing the head of the list. On the first pass, we find the list
length LL. Then we set a pointer to the dummy node and start to move it through
the list till it comes to the (L - n) th node. We relink next pointer of the
(L−n) th node to the (L−n + 2) th node and we are done.*/

public ListNode removeNthFromEnd(ListNode head, int n)
{
  ListNode dummy = new ListNode(0);
  dummy.next = head;
  int length  = 0;
  ListNode first = head;
  while (first != null)
  {
    length++;
    first = first.next;
  }
  length -= n;
  first = dummy;
  while (length > 0)
  {
    length--;
    first = first.next;
  }
  first.next = first.next.next;
  return dummy.next;
}

/*Approach 2: One pass algorithm
Algorithm

The above algorithm could be optimized to one pass. Instead of one pointer,
we could use two pointers. The first pointer advances the list by n + 1 steps from the beginning,
while the second pointer starts from the beginning of the list. Now, both pointers are exactly
separated by nn nodes apart. We maintain this constant gap by advancing both pointers together
until the first pointer arrives past the last node. The second pointer will be pointing at the nth
node counting from the last. We relink the next pointer of the node referenced by the second pointer
to point to the node's next next node.

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
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    ListNode* start = new ListNode(0);
    start->next = head;

    ListNode *ptr1 = start, *ptr2 = start;

    for (int i = 0; i <= n; i++)
    {
      ptr1 = ptr1->next;
    }
    while (ptr1 != NULL)
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    ptr2->next = ptr2->next->next;
    return start->next;

  }
};

