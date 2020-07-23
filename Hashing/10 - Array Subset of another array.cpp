// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> A(n), B(m);
        unordered_map<int, bool> exists;
        for (int i=0; i<n; i++)
        {
            cin>>A[i];
            exists[A[i]] = true;
        }

        bool ok = true;
        for (int i=0; i<m; i++)
        {
            cin>>B[i];
            if (exists[B[i]] == false)
                ok = false;
        }

        if (ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
