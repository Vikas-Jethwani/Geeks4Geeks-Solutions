// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool can_pair_all(vector<int>& arr, int n, int k)
{
    vector<int> buckets(k, 0);
    for (int i=0; i<n; i++)
        buckets[arr[i]%k]++;

    if (buckets[0]%2 == 1)
        return false;

    int i=1, j=k-1;
    for (int i=1, j=k-1; i<=j; i++, j--)
    {
        if (i == j)
        {
            if (buckets[i]%2 == 1)
                return false;
        }
        else
        {
            if ( (buckets[i]+buckets[j])%2 == 0 && buckets[i] == buckets[j])
                continue;
            else
                return false;
        }
    }
    return true;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++)
            cin>>arr[i];
        cin>>k;

        if (can_pair_all(arr, n, k))
            cout<<"True\n";
        else
            cout<<"False\n";
    }
    return 0;
}
