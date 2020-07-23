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
        // if this causes TLE, then use unordered_map and then put in vector and sort
        map<int, int> freq;
        int n1, n2, n3;
        cin>>n1>>n2>>n3;

        vector<long long> arr(n1);
        for (int i=0; i<n1; i++)
        {
            cin>>arr[i];
            if (i > 0 && arr[i] == arr[i-1])
                continue;
            freq[arr[i]]++;
        }

        arr.resize(n2);
        for (int i=0; i<n2; i++)
        {
            cin>>arr[i];
            if (i > 0 && arr[i] == arr[i-1])
                continue;
            freq[arr[i]]++;
        }

        arr.resize(n3);
        for (int i=0; i<n3; i++)
        {
            cin>>arr[i];
            if (i > 0 && arr[i] == arr[i-1])
                continue;
            freq[arr[i]]++;
        }

        bool none_common = true;
        for (auto tr: freq)
        {
            if (tr.second == 3)
            {
                cout<< tr.first <<" ";
                none_common = false;
            }
        }
        if (none_common)
            cout<< -1;
        cout<<endl;
    }
    return 0;
}
