// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int spanningTree(int V,int E,vector<vector<int> > graph);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

int spanningTree(int V,int E,vector<vector<int> > graph)
{
    bool done[V] = {false};
    priority_queue <pair<int, pair<int, int> > > pq; // c, {u,v}
    for (int j=1; j<V; j++) // Put all neighbours of 0 in heap
    {
        if (graph[0][j] != INT_MAX)
        {
            pq.push({-1*graph[0][j], {0, j}}); // -1*Max Heap = Min Heap
        }
    }
    
    long long ans = 0;
    done[0] = true;
    while (!pq.empty())
    {
        int c = -1*pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if (done[u] && done[v])
            continue;
        else
        {
            done[u] = done[v] = true;
            ans += c;
            for (int j=1; j<V; j++)
            {
                if (done[j] == false and graph[v][j] != INT_MAX)
                {
                    pq.push({-1*graph[v][j], {v, j}});
                }
            } 
        }
    }
    return ans;
}
