// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void pairWiseSwap(struct node *head)
{
    node *curr=head;

    while(curr && curr->next)
    {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;

        curr = curr->next->next;
    }
}