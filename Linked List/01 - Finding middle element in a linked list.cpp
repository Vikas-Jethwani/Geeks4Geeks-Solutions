// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int getMiddle(Node *head)
{
    Node *ptr1, *ptr2;
    ptr1 = ptr2 = head;
    while(ptr2 != NULL && ptr2->next != NULL)
    {
        ptr2 = ptr2 -> next;
        ptr1 = ptr1 -> next;
        if(ptr2 != NULL)
            ptr2 = ptr2 -> next;
    }

    return ptr1->data;
}