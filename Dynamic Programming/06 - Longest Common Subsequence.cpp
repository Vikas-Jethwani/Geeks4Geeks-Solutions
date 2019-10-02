/*
    For Length of LCS => Saved space. Space = O(n+m) only.
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int n, m;
string X, Y;

int LCS()
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
        cin>>n>>m;
        cin>>X>>Y;

        cout<<LCS()<<endl;
    }

    return 0;
}
