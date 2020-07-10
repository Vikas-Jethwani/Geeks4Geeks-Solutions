// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int total_visited, int n)
{
    if (total_visited == n && node == 0)
        return true;
    if (visited[node])
        return false;

    visited[node] = true;
    for (int i=0; i<adj[node].size(); i++)
    {
        if (dfs(adj[node][i], adj, visited, total_visited+1, n))
            return true;
    }

    visited[node] = false;
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
        vector <string> inp(n);
        vector <vector<int>> st(26);

        for (int i=0; i<n; i++)
        {
            cin>>inp[i];
            st[inp[i][0] - 'a'].push_back(i);
        }

        vector <vector<int>> adj(n);
        vector <bool> visited(n, false);
        for (int i=0; i<n; i++)
        {
            int last_ch = inp[i][inp[i].length()-1] - 'a';
            for (int j=0; j<st[last_ch].size(); j++)
                adj[i].push_back(st[last_ch][j]);
        }

        cout<< dfs(0, adj, visited, 0, n) <<endl;
    }
    return 0;
}
