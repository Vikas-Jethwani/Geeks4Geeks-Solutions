// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

Node* reverseList(Node *head)
{
    if(head == NULL)
        return NULL;

    Node *p, *q, *r;
    p = NULL;
    q = head;
    r = head->next;

    while(q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if(r != NULL)
            r = r->next;
    }

    return p;
}