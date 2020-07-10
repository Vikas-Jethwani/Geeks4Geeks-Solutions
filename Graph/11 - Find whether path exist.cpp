// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define Src 1
#define Dest 2
#define BlankCell 3
#define Wall 0

bool dfs(int x, int y, int n, const vector<vector<int>> &mat, vector<vector<int>> &visited)
{
    if (x<0 || y<0 || x>=n || y>=n || visited[x][y] || mat[x][y] == Wall)
        return false;
    if (mat[x][y] == Dest)
        return true;

    visited[x][y] = true;

    if (dfs(x+1, y, n, mat, visited))
        return true;
    if (dfs(x, y+1, n, mat, visited))
        return true;
    if (dfs(x-1, y, n, mat, visited))
        return true;
    if (dfs(x, y-1, n, mat, visited))
        return true;

    visited[x][y] = false;
    return false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<int>> mat(n, vector<int> (n));
        vector<vector<int>> visited(n, vector<int> (n, false));

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin>>mat[i][j];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (mat[i][j] == Src)
                    cout<< dfs(i, j, n, mat, visited) <<endl;
    }
    return 0;
}
