/*
    Space = O(n+W) Optimized.
    Time  = O(n.W)
*/
/*
    Much Better and easier to understand code.
    https://ide.geeksforgeeks.org/glmrHUiCHq
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 10005

int n, W;
int profit[MAX], weight[MAX];

int Knapsack0_1()
{
    int temp[2][W+1], maxLen=0, curr=0; // Current active array
    for(int i=0; i<=W; i++)
        temp[0][i] = temp[1][i] = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(weight[i] <= j)
            {
                temp[curr][j] = max( (profit[i]+temp[!curr][j-weight[i]]) , temp[!curr][j] );
            }
            else
                temp[curr][j] = temp[!curr][j];
        }
        curr = !curr; // curr = 1 - curr; works same way.
    }

    return temp[!curr][W];
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>W;

        for(int i=0; i<n; i++)
            cin>>profit[i];
        for(int i=0; i<n; i++)
            cin>>weight[i];

        cout<<Knapsack0_1()<<endl;
    }

    return 0;
}
