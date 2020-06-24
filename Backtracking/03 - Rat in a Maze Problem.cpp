// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector< vector<char> > ans;
vector<char> curr;
bool visited[MAX][MAX];

void dfs(int x, int y, int mat[MAX][MAX], int n)
{
    if (x<0 || y<0 || x>=n || y>=n)
        return;
    if (mat[x][y] == 0)
        return;
    if (visited[x][y])
        return;
    if (x == n-1 && y== n-1)
    {
        vector<char> temp = curr;
        ans.push_back(temp);
        return;
    }

    visited[x][y] = true;

    curr.push_back('U');
    dfs(x-1, y, mat, n);
    curr.pop_back();
    
    curr.push_back('D');
    dfs(x+1, y, mat, n);
    curr.pop_back();

    curr.push_back('R');
    dfs(x, y+1, mat, n);
    curr.pop_back();

    curr.push_back('L');
    dfs(x, y-1, mat, n);
    curr.pop_back();

    visited[x][y] = false;
}

vector<string> printPath(int mat[MAX][MAX], int n)
{
    vector<string> return_ans;
    return_ans.clear();
    ans.clear();
    curr.clear();
    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
            visited[i][j] = false;

    dfs(0, 0, mat, n);

    if (ans.size() == 0)
    {
        return return_ans;
    }
    for (int i=0; i<ans.size(); i++)
    {
        string temp = "";
        for (int j=0; j<ans[i].size(); j++)
        {
            temp += ans[i][j];
        }
        return_ans.push_back(temp);
    }
    sort(return_ans.begin(), return_ans.end());
    return return_ans;
}
