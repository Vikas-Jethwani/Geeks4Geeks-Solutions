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
        int n, m, x;
        cin>>n>>m>>x;
        unordered_map<int, bool> exists;
        vector<int> ans;

        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            exists[temp] = true;
        }
        for (int temp, i=0; i<m; i++)
        {
            cin>>temp;
            if (exists[x-temp])
                ans.push_back(x-temp);
        }

        sort(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); i++)
        {
            if (i == ans.size()-1)
                cout<<ans[i]<<" "<<x-ans[i]<<endl;
            else
                cout<<ans[i]<<" "<<x-ans[i]<<", ";
        }
        if (ans.size() == 0)
            cout<<-1<<endl;
    }
    return 0;
}
