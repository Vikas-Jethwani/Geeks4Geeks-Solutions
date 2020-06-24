// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int n, m;
char mat[8][8];
bool visited[8][8];
unordered_map <string, bool> dictionary;

bool go_more(string s)
{
    bool ok = false;
    for (auto tr: dictionary)
    {
        if (tr.second == true)
            continue;
        if (tr.first == s)
        {
            dictionary[s] = true;
            continue;
        }

        string curr = tr.first;
        int n = s.size();
        if (curr.size() > n)
        {
            for (int i=0; i<curr.size(); i++)
            {
                if (i<n && curr[i] != s[i])
                    break;
                if (i == n)
                    ok = true;
            }
        }
    }
    return ok;
}

void dfs(int x, int y, string temp)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return;
    if (visited[x][y])
        return;

    visited[x][y] = true;
    temp += mat[x][y];
    if (go_more(temp))
    {
        dfs(x+1, y, temp);
        dfs(x-1, y, temp);
        dfs(x, y+1, temp);
        dfs(x, y-1, temp);
        dfs(x+1, y+1, temp);
        dfs(x+1, y-1, temp);
        dfs(x-1, y+1, temp);
        dfs(x-1, y-1, temp);
    }
    visited[x][y] = false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        dictionary.clear();
        int x;
        cin>>x;
        for (int i=0; i<x; i++)
        {
            string temp;
            cin>>temp;
            dictionary[temp] = false;
        }

        cin>>n>>m;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                cin>>mat[i][j];
                visited[i][j] = false;
            }
        }

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
                dfs(i, j, "");
        }

        vector<string> found;
        found.clear();
        for (auto tr: dictionary)
        {
            if (tr.second == true)
                found.push_back(tr.first);
        }

        if (found.size() == 0)
            cout<<-1<<endl;
        else
        {
            sort(found.begin(), found.end());
            for (int i=0; i<found.size(); i++)
                cout<<found[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
