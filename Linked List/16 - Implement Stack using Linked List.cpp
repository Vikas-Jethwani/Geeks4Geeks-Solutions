// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void MyStack :: push(int x)
{
    StackNode *temp=new StackNode(x);
    if(top == NULL) // First node
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

int MyStack :: pop()
{
    if(top == NULL) // No nodes
        return -1;
    
    int res;
    res = top->data;
    
    StackNode *temp;
    temp = top;
    top = top->next;
    free(temp);
    temp = NULL;
    
    return res;
}