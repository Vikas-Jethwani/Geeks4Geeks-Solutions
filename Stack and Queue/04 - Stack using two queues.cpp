// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

int turn = 1;
void QueueStack :: push(int x)
{
    if(turn == 1)
        q1.push(x);
    else
        q2.push(x);
}

int QueueStack :: pop()
{
    int x = -1; // If queues are empty
    if(turn == 1)
    {
        while(!q1.empty())
        {
            x = q1.front();
            q1.pop();
            if(!q1.empty()) // If it is not the last element
                q2.push(x);
        }
        turn = 2;
    }
    else
    {
        while(!q2.empty())
        {
            x = q2.front();
            q2.pop();
            if(!q2.empty()) // If it is not the last element
                q1.push(x);
        }
        turn = 1;
    }

    return x;
}