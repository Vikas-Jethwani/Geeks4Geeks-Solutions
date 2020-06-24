// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int mat[9][9];

bool can_fill(int x, int y, int val)
{
    // Row check
    for (int j=0; j<9; j++)
        if (mat[x][j] == val)
            return false;

    // Col check
    for (int i=0; i<9; i++)
        if (mat[i][y] == val)
            return false;

    // Box check
    for (int i=3*(int(x/3)); i<3*(int(x/3)+1); i++)
    {
        for (int j=3*(int(y/3)); j<3*(int(y/3)+1); j++)
            if (mat[i][j] == val)
                return false;
    }

    return true;
}

bool dfs(int x, int y)
{
    if (x == 9 && y == 0)
        return true;
    
    if (mat[x][y] != 0)
    {
        if (y == 8)
            return dfs(x+1, 0);
        return dfs(x, y+1);
    }

    for (int i=1; i<=9; i++)
    {
        if (can_fill(x, y, i))
        {
            mat[x][y] = i;
            if (y == 8 && dfs(x+1, 0))
                return true;
            if (y < 8 && dfs(x, y+1))
                return true;
            mat[x][y] = 0;
        }
    }

    return false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                cin>>mat[i][j];

        dfs(0, 0);

        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
