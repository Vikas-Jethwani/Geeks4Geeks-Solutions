// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int mat[105][105];
int n, m;

void dfs(int x, int y, int old_color, int new_color)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return;
    if (mat[x][y] != old_color)
        return;

    mat[x][y] = new_color;
    dfs(x+1, y, old_color, new_color);
    dfs(x-1, y, old_color, new_color);
    dfs(x, y+1, old_color, new_color);
    dfs(x, y-1, old_color, new_color);
}


int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int x, y, k;
        cin>>n>>m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin>>mat[i][j];

        cin>>x>>y>>k;

        dfs(x, y, mat[x][y], k);

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
