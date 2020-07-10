// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 100005
int dp[MAX][26];
int mx_row;

bool lowercase = true; // EDIT here for lowercase only

void clear()
{
    mx_row = 0;
    for (int i=0; i<MAX; i++)
        for (int j=0; j<26; j++)
            dp[i][j] = -1;
}

void insert(string word)
{
    int col, curr = 0;
    for (int i=0; i<word.size(); i++)
    {
        if (lowercase)
            col = word[i] - 'a';
        else
            col = word[i] - 'A';

        if (dp[curr][col] == -1)
        {
            dp[curr][col] = ++mx_row;
            curr = mx_row;
        }
        else
            curr = dp[curr][col];
    }
}

// ------------------------------
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
// ------------------------------

string findOrder(string dict[], int N, int K)
{
    clear();
    for (int i=0; i<N; i++)
        insert(dict[i]);

    vector<int> adj[K];
    for (int i=0; i<MAX; i++)
    {
        vector<pair<int,int>> vc;
        for (int j=0; j<26; j++)
            if (dp[i][j] != -1)
                vc.push_back({dp[i][j], j});

        if (vc.size() > 1)
        {
            sort(vc.begin(), vc.end());
            for (int j=0; j<vc.size()-1; j++)
                adj[vc[j].second].push_back(vc[j+1].second);
        }
    }

    vector<int> ans = topoSort(K, adj);
    string ret_ans = "";
    for (int i=0; i<ans.size(); i++)
        ret_ans += string(1, ans[i] + 'a');

    return ret_ans;
}
