// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

Node *flatten(Node *root)
{
    vector<int> vec;
    vec.clear();
    Node *right, *temp, *par;

    right = root;
    while(right != NULL)
    {
        temp = right;
        right = right->next;

        while(temp != NULL)
        {
            vec.push_back(temp->data);
            par = temp;
            temp = temp->bottom;
        }
        par->bottom = right;
    }

    temp=root;
    sort(vec.begin(), vec.end());
    int pos=0;
    while(temp != NULL)
    {
        temp->data = vec[pos++];
        temp->next = NULL;
        temp = temp->bottom;
    }

    return root;
}