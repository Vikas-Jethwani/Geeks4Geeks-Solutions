// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int getNthFromLast(Node *head, int n)
{
    int count=0;
    Node *curr=head;
    Node *nthLast=NULL;

    while(curr != NULL)
    {
        count++;
        curr = curr->next;

        if(count == n)
        {
            nthLast = head;
        }
        else if(count > n)
            nthLast = nthLast->next;
    }

    if(nthLast == NULL)
        return -1;
    else
        return nthLast->data;
}