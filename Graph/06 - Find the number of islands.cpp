// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

void dfs(int x, int y, int N, int M, vector<int> mat[], bool visited[][100])
{
    if (x<0 || y<0 || x>=N || y>=M || visited[x][y] || mat[x][y]==0)
        return;

    visited[x][y] = true;

    dfs(x+1, y, N, M, mat, visited);
    dfs(x, y+1, N, M, mat, visited);
    dfs(x-1, y, N, M, mat, visited);
    dfs(x, y-1, N, M, mat, visited);
    dfs(x+1, y+1, N, M, mat, visited);
    dfs(x+1, y-1, N, M, mat, visited);
    dfs(x-1, y+1, N, M, mat, visited);
    dfs(x-1, y-1, N, M, mat, visited);
}

int findIslands(vector<int> mat[], int N, int M)
{
    int ans = 0;
    bool visited[N][100] = {false};

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (mat[i][j] == 1 && visited[i][j] == false)
            {
                ans++;
                dfs(i, j, N, M, mat, visited);
            }
        }
    }

    return ans;
}
