// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

unordered_map <int, int> indeg;
stack <int> todo; // can use vector or queue too
vector <int> ans;

vector<int> topoSort(int V, vector<int> adj[])
{
    indeg.clear();
    while (!todo.empty())
        todo.pop();
    ans.clear();

    for (int i=0; i<V; i++)
        for (int j=0; j<adj[i].size(); j++)
            indeg[adj[i][j]]++;

    for (int i=0; i<V; i++)
        if (indeg[i] == 0)
            todo.push(i);

    while (!todo.empty())
    {
        int node = todo.top();
        todo.pop();
        ans.push_back(node);

        for (int i=0; i<adj[node].size(); i++)
        {
            indeg[adj[node][i]]--;
            if (indeg[adj[node][i]] == 0)
                todo.push(adj[node][i]);
        }
    }

    return ans;
}

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];

    for (int i=0; i<N-1; i++)
    {
        int j=0;
        while (j<dict[i].length() && j<dict[i+1].length() && dict[i][j] == dict[i+1][j])
            j++;

        if (j<dict[i].length() && j<dict[i+1].length())
            adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
    }

    vector<int> ans = topoSort(K, adj);
    string ret_ans = "";
    for (int i=0; i<ans.size(); i++)
        ret_ans += string(1, ans[i] + 'a');

    return ret_ans;
}
