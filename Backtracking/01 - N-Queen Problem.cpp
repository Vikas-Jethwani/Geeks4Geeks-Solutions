// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector< vector<int> > ans;
vector<int> curr;
int mat[10][10];
int n;

void put_remove(int x, int y, int val)
{
    int i, j;
    // Center
    mat[x][y] += val;

    // North
    for (i=x-1; i>=0; i--)
        mat[i][y] += val;
    // North-East
    i = x-1; j = y+1;
    while (i>=0 && j>=0 && i<n && j<n)
    {
        mat[i][j] += val;
        i--;
        j++;
    }

    // East
    for (j=y+1; j<n; j++)
        mat[x][j] += val;
    // South-East
    i = x+1; j = y+1;
    while (i>=0 && j>=0 && i<n && j<n)
    {
        mat[i][j] += val;
        i++;
        j++;
    }

    // South
    for (i=x+1; i<n; i++)
        mat[i][y] += val;
    // South-West
    i = x+1; j = y-1;
    while (i>=0 && j>=0 && i<n && j<n)
    {
        mat[i][j] += val;
        i++;
        j--;
    }

    // West
    for (j=y-1; j>=0; j--)
        mat[x][j] += val;
    // South-West
    i = x-1; j = y-1;
    while (i>=0 && j>=0 && i<n && j<n)
    {
        mat[i][j] += val;
        i--;
        j--;
    }
}

// Column-Wise
void dfs(int col)
{
    if (col == n)
    {
        vector<int> temp = curr;
        ans.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (mat[i][col] == 0)
        {
            put_remove(i, col, 1);
            curr.push_back(i);
            dfs(col+1);
            curr.pop_back();
            put_remove(i, col, -1);
        }
    }
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans.clear();
        curr.clear();
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                mat[i][j] = 0;

        dfs(0);

        if (ans.size() == 0)
        {
            cout<<"-1\n";
            continue;
        }
        for (int i=0; i<ans.size(); i++)
        {
            cout<<"[";
            for (int j=0; j<ans[i].size(); j++)
            {
                cout<<ans[i][j]+1<<" ";
            }
            cout<<"] ";
        }
        cout<<endl;
    }
    return 0;
}
