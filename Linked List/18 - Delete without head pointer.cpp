// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void deleteNode(Node *node)
{
    Node *par = node;
    node = node->next;

    while(node->next != NULL)
    {
        par->data = node->data;
        par = node;
        node = node->next;
    }
    
    par->data = node->data;
    par->next = NULL; 
}