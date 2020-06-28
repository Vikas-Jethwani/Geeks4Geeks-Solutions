// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector <int> bfs(vector<int> adj[], int N)
{
    bool visited[N] = {false};
    queue <int> q;
    q.push(0);
    vector<int>ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        ans.push_back(node);
        for (int i=0; i<adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}
