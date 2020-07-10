// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define ds_type pair<int, int>

int solve(vector<pair<int, int>> adj[30])
{
    priority_queue< ds_type, vector<ds_type>, greater<ds_type> > pq; // {moves, pos}
    vector<bool> visited(30, false);

    pq.push({0, 0});
    while (!pq.empty())
    {
        int moves = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (pos == 29)
            return moves;

        visited[pos] = true;
        for (int i=0; i<adj[pos].size(); i++)
        {
            int jump = adj[pos][i].first;
            int dest = adj[pos][i].second;
            if (!visited[dest])
            {
                if (jump)
                    pq.push({moves, dest});
                else
                    pq.push({moves+1, dest});
            }
        }
    }
    return -1;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<pair<int, int>> adj[30]; // {normal/jump , dest}
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            int a, b;
            cin>>a>>b;
            a--; b--;
            adj[a].push_back({1, b});
        }
        for (int i=0; i<30; i++)
        {
            // No snakes or ladder here
            if (adj[i].empty())
            {
                for (int j=1; j<=6; j++)
                    if (i+j < 30)
                        adj[i].push_back({0, i+j});
            }
        }

        cout<< solve(adj) <<endl;
    }
    return 0;
}
