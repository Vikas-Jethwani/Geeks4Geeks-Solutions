// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int detectloop(Node *head)
{
    unordered_map<Node *, bool> hash;
    
    while(head != NULL)
    {
        if(hash[head]) // Already visited this node
            return 1;
        hash[head] = true;
        head = head->next;
    }

    return 0;
}