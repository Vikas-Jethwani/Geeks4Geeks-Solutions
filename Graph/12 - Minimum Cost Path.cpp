/*
    Stupid GFG test cases and time allotment.
    My normal implementation of PQ gave TLE.
    While this approach and normal Queue approach also gave AC. 
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define ds_type pair<int, pair<int, int>>
vector<int> dx = {0,1,0,-1}; // E,S,W,N
vector<int> dy = {1,0,-1,0};

int bfs(vector<vector<int>> &mat, int n)
{
    priority_queue< ds_type, vector<ds_type>, greater<ds_type> > pq; // val, {x,y}
    vector<vector<int>> dist (n, vector<int> (n, INT_MAX));

    dist[0][0] = mat[0][0];
    pq.push({dist[0][0], {0,0}});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int i=0; i<dx.size(); i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 0 || Y < 0 || X >= n || Y >= n)
                continue;
            if (dist[X][Y] <= dist[x][y] + mat[X][Y])
                continue;

            dist[X][Y] = dist[x][y] + mat[X][Y];
            pq.push({dist[X][Y], {X, Y}});
        }
    }
    return dist[n-1][n-1];
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<int>> mat (n, vector<int> (n));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin>>mat[i][j];

        cout<< bfs(mat, n) <<endl;
    }
    return 0;
}
