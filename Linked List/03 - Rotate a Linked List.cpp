// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

Node* rotate(Node* head, int k)
{
    if(head == NULL)
        return NULL;

    int count=0;
    Node *par, *prev, *new_head;
    par = head;
    new_head = NULL;

    while(par->next != NULL)
    {
        count++;
        prev = par;
        par = par->next;
        if(count == k)
        {
            prev->next = NULL;
            new_head = par;
        }
    }

    if(new_head == NULL) // when k==n
        new_head = head;
    else
        par->next = head; // normal case, join end to head

    return new_head;
}