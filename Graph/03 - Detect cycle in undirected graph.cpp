// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool dfs(int node, vector<int> adj[], bool visited[], int par)
{
    if (visited[node])
        return true;
    visited[node] = true;

    for (int i=0; i<adj[node].size(); i++)
    {
        if (adj[node][i] != par)
        {
            if (dfs(adj[node][i], adj, visited, node))
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    
    for (int i=0; i<V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, -1))
                return true;
        }
    }
    return false;
}
