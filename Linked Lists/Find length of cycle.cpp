#include<bits/stdc++.h>
using namespace std;

class linked_list
{
public:
    int data;
    linked_list *next;
    linked_list()
    {
        this->next = NULL;
    }
    linked_list(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    linked_list *add(linked_list *head, int data)
    {
        if (head == NULL)
        {
            linked_list *temp = new linked_list(data);
            head = temp;
        }
        else
        {
            linked_list *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new linked_list(data);
        }
        return head;
    }

    void print(linked_list *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
    int cycle_length(linked_list *head)
    {
        linked_list *slow = head, *fast = head;

        while (fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return -1;
        slow = head;

        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        cout << slow->next->data << " " << fast->next->data << "\n";
        linked_list *temp = slow->next;
        int cnt = 1;
        while (temp != fast)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    linked_list *swap_nodes_without_swapping_data(linked_list* head, int x, int y)
    {
        linked_list *prevX = NULL, *currX = head;
        linked_list *prevY = NULL, *currY = head;

        while (currX and currX->data != x)
        {
            prevX = currX;
            currX = currX->next;
        }
        while (currY and currY->data != y)
        {
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL or currY == NULL)
            return head;

        if (prevX == NULL)
            head = currY;
        else
            prevX->next = currY;

        if (prevY == NULL)
            head = currX;
        else
            prevY->next = currX;

        linked_list *temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;

        return head;
    }
};

int main()
{
    linked_list *head = NULL;

    head = head->add(head, 1);
    head = head->add(head, 2);
    head = head->add(head, 3);
    head = head->add(head, 4);
    head = head->add(head, 5);
    head = head->add(head, 6);

    head->print(head);
    /*******************************

        linked_list *temp1 = head;

        while (temp1->data != 2)
            temp1 = temp1->next;

        cout << temp1->data << "\n";
        linked_list *temp2 = head;

        while (temp2->next)
            temp2 = temp2->next;

        cout << temp2->data << "\n";

        temp2->next = temp1;

        cout << head->cycle_length(head);

    **********************************/

    head = head->swap_nodes_without_swapping_data(head, 2, 5);
    head->print(head);
    return 0;
}

