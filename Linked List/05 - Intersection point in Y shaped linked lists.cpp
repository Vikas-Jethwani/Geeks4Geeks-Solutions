// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node *, bool> hash;

    while(head1 != NULL)
    {
        hash[head1] = true;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        if(hash[head2]) // Already visited this node
            return head2->data;
        head2 = head2->next;
    }

    return -1;
}