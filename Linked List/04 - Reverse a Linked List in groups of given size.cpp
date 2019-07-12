// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

struct node *reverse (struct node *head, int k)
{
    if(head == NULL)
        return NULL;

    int count=0;
    node *p, *q, *r, *old_head, *par, *ret_head;
    p = NULL;
    q = head;
    r = head->next;
    old_head = NULL;
    par = head;

    while(q != NULL)
    {
        count++;
        if(count == k+1)
        {
            count = 1;
            if(old_head == NULL)
                ret_head = p;
            else
                old_head->next = p;
            old_head = par;
            par = q;
            p = NULL;
        }

        q->next = p;
        p = q;
        q = r;
        if(r != NULL)
            r = r->next;
    }
    if(old_head == NULL)
        ret_head = p;
    else
        old_head->next = p;
    old_head = par;
    par = q;
    p = NULL;

    return ret_head;
}