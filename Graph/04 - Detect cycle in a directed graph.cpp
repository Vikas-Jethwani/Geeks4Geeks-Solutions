// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool dfs(int node, vector<int> adj[], int visited[])
{
    if (visited[node] == 1) // To detect cycle, save this node and add extra param of parent.
        return true;
    if (visited[node] == 2)
        return false;

    visited[node] = 1;
    for (int i=0; i<adj[node].size(); i++)
    {
        if (dfs(adj[node][i], adj, visited))
            return true;
    }

    visited[node] = 2;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int visited[V]; // 0=White, 1=Grey(cycle), 2=Black
    for (int i=0; i<V; i++)
        visited[i]=0;

    for (int i=0; i<V; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i, adj, visited))
                return true;
            visited[i] = 2;
        }
    }
    return false;
}
