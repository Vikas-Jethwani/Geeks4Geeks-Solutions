// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

Node* sortedMerge(Node* head1,   Node* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    Node *head, *curr;
    if(head1->data < head2->data)
    {
        head = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        head2 = head2->next;
    }

    curr = head;
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if(head1)
    {
        curr->next = head1;
    }
    if(head2)
    {
        curr->next = head2;
    }

    return head;
}