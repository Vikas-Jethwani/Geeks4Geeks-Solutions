/*
    Looks O(n^2), but it is O(n).
    Inner loop only runs for first element of consecutive series.
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int subseq(vector<int>& arr, int n)
{
    unordered_map<int, bool> exists;
    for (int i=0; i<n; i++)
        exists[arr[i]] = true;

    int ans = 0;
    for (int i=0; i<n; i++)
    {
        if (exists[arr[i] - 1] == false)
        {
            int curr = 0;
            for (int j=arr[i]; true; j++)
            {
                if (exists[j])
                    curr++;
                else
                    break;
            }
            ans = max(ans, curr);
        }
    }
    return ans;
}


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

        cout<< subseq(arr, n) <<endl;
    }
    return 0;
}
