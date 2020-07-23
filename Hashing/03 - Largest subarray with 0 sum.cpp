// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int maxLen(int A[],int n)
{
    int prefix_sum[n];
    map <int, int> hash;
    int max_len = 0;

    prefix_sum[0] = A[0];
    hash[prefix_sum[0]] = 0;
    hash[0] = -1;

    for(int i=1; i<n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + A[i];
        if(hash.find(prefix_sum[i]) == hash.end())
        {
            //Doesn't Exist
            hash[prefix_sum[i]] = i;
        }
    }

    for(int i=0; i<n; i++)
    {
        int curr_best = i - hash[prefix_sum[i]];
        max_len = max(max_len, curr_best);
    }

    return max_len;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<<maxLen(arr, n);
    }
    return 0;
}