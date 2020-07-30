/*
    Looks tough at first, but just remember:
    map<int, vector<int>> if you need to also know indices. e.g. [mm[0][0]+1, curr_idx]
*/
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++)
            cin>>arr[i];

        unordered_map<int, int> mm;
        int curr=0, ans=0;
        // mm[0]++;
        for (int i=0; i<n; i++)
        {
            curr += arr[i];
            if (curr == 0) // This means from index 0 upto now, sum == 0.
                ans++;
            ans += mm[curr];
            mm[curr]++;
        }

        cout<<ans<<endl;
    }
    return 0;
}
