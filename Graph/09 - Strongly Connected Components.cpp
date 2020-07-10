// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

stack<int> order;

void dfs(int node, vector<int> adj[], vector<bool> &visited, bool push)
{
    if (visited[node])
        return;
    visited[node] = true;

    for (int i=0; i<adj[node].size(); i++)
        dfs(adj[node][i], adj, visited, push);

    if (push)
        order.push(node);
}

int kosaraju(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    while (!order.empty())
        order.pop();

    for (int i=0; i<V; i++)
    {
        if (visited[i] == false)
            dfs(i, adj, visited, true);
    }

    // Reverse Edges
    vector<int> rev_adj[V];
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<adj[i].size(); j++)
            rev_adj[adj[i][j]].push_back(i);
    }

    int ans = 0;
    for (int i=0; i<V; i++)
        visited[i] = false;
    while (!order.empty())
    {
        if (!visited[order.top()])
        {
            ans++;
            dfs(order.top(), rev_adj, visited, false);
        }
        order.pop();
    }

    return ans;
}
