// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int n, m;
char mat[8][8];
bool visited[8][8];
set<string> found;

#define SIZE 126 // As Testcases had both lower and uppercase.
struct Trie
{
    struct Trie *children[SIZE];
    bool ends_here;
    Trie ()
    {
        ends_here = false;
        for (int i=0; i<SIZE; i++)
            children[i] = NULL;
    }
};
struct Trie *root;

void insert(string word)
{
    struct Trie *ptr = root;
    for (int i=0; i<word.size(); i++)
    {
        int col = word[i];
        if (!ptr->children[col])
            ptr->children[col] = new Trie();

        ptr = ptr->children[col];
    }
    ptr->ends_here = true;
}

bool exists(string word)
{
    struct Trie *ptr = root;    
    for (int i=0; i<word.size(); i++)
    {
        int col = word[i];
        if (!ptr->children[col])
            return false;

        ptr = ptr->children[col];
    }
    return (ptr != NULL && ptr->ends_here);
}

// Proper prefix Function
bool prefix(string word)
{
    struct Trie *ptr = root;    
    for (int i=0; i<word.size(); i++)
    {
        int col = word[i];
        if (!ptr->children[col])
            return false;

        ptr = ptr->children[col];
    }
    if (ptr == NULL)
        return false;

    // Just Uncomment the below line to consider full string as prefix too.
    // return true; // Uncommenting this will skip the below check.
    
    bool has_children = false;
    for (int i=0; i<SIZE; i++)
    {
        if (ptr->children[i] != NULL)
        {
            has_children = true;
            break;
        }
    }
    return has_children; // Proper prefix.
}


void dfs(int x, int y, string temp)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return;
    if (visited[x][y])
        return;

    visited[x][y] = true;
    temp += mat[x][y];
    if (exists(temp))
    {
        found.insert(temp);
    }
    if (prefix(temp))
    {
        dfs(x+1, y, temp);
        dfs(x-1, y, temp);
        dfs(x, y+1, temp);
        dfs(x, y-1, temp);
        dfs(x+1, y+1, temp);
        dfs(x+1, y-1, temp);
        dfs(x-1, y+1, temp);
        dfs(x-1, y-1, temp);
    }
    visited[x][y] = false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        root = new Trie(); // Not a good way. Should use 'delete'
        found.clear();
        int x;
        cin>>x;
        for (int i=0; i<x; i++)
        {
            string temp;
            cin>>temp;
            insert(temp);
        }

        cin>>n>>m;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                cin>>mat[i][j];
                visited[i][j] = false;
            }
        }

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
                dfs(i, j, "");
        }


        if (found.size() == 0)
            cout<<-1<<endl;
        else
        {
            vector<string> ans;
            for (auto tr: found)
                ans.push_back(tr);
            sort(ans.begin(), ans.end());
            for (int i=0; i<ans.size(); i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
