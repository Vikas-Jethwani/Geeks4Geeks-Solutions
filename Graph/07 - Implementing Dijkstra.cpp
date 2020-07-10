/*
    O(V^2)
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector <int> dijkstra(vector<vector<int>> adj, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq; // dist, idx

    pq.push({0, src});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (d >= dist[idx])
            continue;

        dist[idx] = d;
        for (int i=0; i<adj[idx].size(); i++)
        {
            if (adj[idx][i] != 0 && dist[i] == INT_MAX)
                pq.push({dist[idx]+adj[idx][i], i});
        }
    }

    return dist;
}
