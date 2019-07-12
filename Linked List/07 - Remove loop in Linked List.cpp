// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void removeTheLoop(Node *head)
{
    unordered_map<Node *, bool> hash;
    Node *curr=head;
    Node *par=NULL;
    
    while(curr != NULL)
    {
        if(hash[curr])
        {
            par->next = NULL;
            break;
        }
        hash[curr] = true;
        par = curr;
        curr = curr->next;
    }
}