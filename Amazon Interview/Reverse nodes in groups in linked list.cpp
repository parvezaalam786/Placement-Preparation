/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x
#define all(x) (x).begin(),(x).end()

class linkedList
{
    int data;
    linkedList* next;
public:
    linkedList()
    {
        this->next = NULL;
    }
    linkedList(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    linkedList *insert(linkedList *head, int x)
    {
        if (head == NULL)
            return new linkedList(x);
        linkedList *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new linkedList(x);
        return head;
    }

    void printList(linkedList *head)
    {
        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "\n";
    }
    linkedList *reverseKRecursive(linkedList *head, int k)
    {
        linkedList* curr = head, *next = NULL, *prev = NULL;
        int cnt = 0;
        while (curr != NULL and cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if (next != NULL)
        {
            linkedList* reshead = reverseKRecursive(next, k);
            head->next = reshead;
        }
        return prev;
    }
    linkedList *reverseKIterative(linkedList *head, int k)
    {
        linkedList *curr = head, *prevFirst = NULL;
        bool isFirstPass = true;

        while (curr != NULL)
        {
            linkedList *first = curr, *prev = NULL;
            int cnt = 0;
            while (curr != NULL and cnt < k)
            {
                linkedList *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                cnt++;
            }
            if (isFirstPass)
            {
                head = prev;
                isFirstPass = false;
            }
            else
            {
                prevFirst->next = prev;
            }
            prevFirst = first;
        }
        return head;
    }
};


void solve()
{
    linkedList *head = NULL;
    head = head->insert(head, 1);
    head = head->insert(head, 2);
    head = head->insert(head, 3);
    head = head->insert(head, 4);
    head = head->insert(head, 5);
    head = head->insert(head, 6);
    head = head->insert(head, 7);
    head = head->insert(head, 8);
    head = head->insert(head, 9);
    head = head->insert(head, 10);

    head->printList(head);
    head = head->reverseKRecursive(head, 4);
    head->printList(head);
    head = head->reverseKIterative(head, 4);
    head->printList(head);

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
