// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    int x;
    if(s2.empty())
    {
        while(!s1.empty())
        {
            x = s1.top();
            s1.pop();
            s2.push( x );
        }
    }

    if(s2.empty())
        x = -1;
    else
    {
        x = s2.top();
        s2.pop();
    }

    return x;
}