// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 25
int n, m;
int mat[MAX][MAX];

int solve(int x, int y)
{
    int dp[n][m];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            dp[i][j] = INT_MAX;

    queue <pair<int, pair<int, int>>> q; // val, {i,j}
    q.push({0,{0,0}});
    while (!q.empty())
    {
        int val = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();

        if (i<0 || j<0 || i>=n || j>=m)
            continue;
        if (mat[i][j] == 0)
            continue;
        if (dp[i][j] <= val)
            continue;
        dp[i][j] = val;

        q.push({val+1, {i+1,j}});
        q.push({val+1, {i,j+1}});
        q.push({val+1, {i-1,j}});
        q.push({val+1, {i,j-1}});
    }

    if (dp[x][y] == INT_MAX)
        return -1;
    else
        return dp[x][y];
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin>>mat[i][j];

        int x, y;
        cin>>x>>y;

        cout<< solve(x, y) <<endl;
    }
    return 0;
}
