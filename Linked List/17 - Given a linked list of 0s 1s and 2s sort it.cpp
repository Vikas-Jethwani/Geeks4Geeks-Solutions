// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

Node* segregate(Node *head)
{
    int count[3] = {0,0,0};
    Node *temp;

    for(temp=head; temp!=NULL; temp=temp->next)
    {
        count[temp->data]++;
    }

    int idx=0;
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        while(count[idx] == 0) idx++;
        temp->data = idx;
        count[idx]--;
    }

    return head;
}