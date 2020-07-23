// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool myComp(pair<int, int> ff, pair<int, int> ss)
{
    if (ff.first > ss.first)
        return true;
    else if (ff.first < ss.first)
        return false;
    else
        return ff.second < ss.second; 
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        unordered_map<int, int> freq;
        vector<pair<int, int>> ans;
        cin>>n;
        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            freq[temp]++;
        }
        for (auto tr: freq)
        {
            ans.push_back({tr.second, tr.first});
        }

        sort(ans.begin(), ans.end(), myComp);

        for (int i=0; i<ans.size(); i++)
        {
            int f = ans[i].first;
            int val = ans[i].second;
            while (f--)
                cout<< val <<" "; 
        }
        cout<<endl;
    }
    return 0;
}
