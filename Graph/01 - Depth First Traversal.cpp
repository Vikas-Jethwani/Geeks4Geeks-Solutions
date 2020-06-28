// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector <int> dfs(vector<int> adj[], int N)
{
    bool visited[N] = {false};
    stack <int> s;
    s.push(0);
    vector<int>ans;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        ans.push_back(node);
        for (int i=adj[node].size()-1; i>=0; i--) // in reverse cause GFG was only accepting this way
        {
            if (!visited[adj[node][i]])
            {
                s.push(adj[node][i]);
            }
        }
    }

    return ans;
}
