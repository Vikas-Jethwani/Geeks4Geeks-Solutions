// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int detectloop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        if(slow == fast)
            return 1;
    }

    return 0;
}