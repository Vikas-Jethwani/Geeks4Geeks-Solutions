// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void MyQueue :: push(int x)
{
    QueueNode *temp=new QueueNode(x);
    if(rear == NULL) // First node
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;
    }
}

int MyQueue :: pop()
{
    if(front == NULL) // No nodes
        return -1;
    
    int res;
    res = front->data;
    if(front == rear) // Only 1 node left
    {
        front = NULL;
        free(rear);
        rear = NULL;
    }
    else
    {
        QueueNode *temp;
        temp = front;
        front = front->next;
        free(temp);
        temp = NULL;
    }

    return res;
}