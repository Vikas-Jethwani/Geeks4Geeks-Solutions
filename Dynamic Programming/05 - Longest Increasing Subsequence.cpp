/*
    O(n^2)
    For Length of LCS => Saved space. Space = O(n+m) only.
    Longest Increasing Subsequences => LCS(sorted arr, arr)
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int n, m;

int LCS(int X[], int Y[])
{
    int temp[2][m+1], curr=0; // Current active array
    for(int i=0; i<=m; i++)
        temp[0][i] = temp[1][i] = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(X[i] == Y[j])
            {
                temp[curr][j+1] = 1 + temp[!curr][j]; // j+1 => 1 based array to manage left side case
            }
            else
            {
                temp[curr][j+1] = max(temp[!curr][j+1], temp[curr][j]);
            }
        }
        curr = !curr; // curr = 1 - curr; works same way.
    }

    return temp[!curr][m];
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int X[n], Y[n];

        for(int i=0; i<n; i++)
        {
            cin>>X[i];
            Y[i] = X[i];
        }

        sort(X, X+n);

        // Remove Duplicates for monotonically increasing sequence
        int n_dash=0, prev=-1;
        for(int i=0; i<n; i++)
        {
            if(prev != X[i])
            {
                prev = X[i];
                X[n_dash++] = X[i];
            }
        }
        m=n;
        n=n_dash;

        cout<<LCS(X, Y)<<endl;
    }

    return 0;
}
