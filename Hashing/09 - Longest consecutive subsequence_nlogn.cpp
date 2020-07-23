// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int subseq(vector<int>& arr, int n)
{
    sort(arr.begin(), arr.end());
    arr.erase( unique( arr.begin(), arr.end() ), arr.end() );

    int ans = 0, start = 0;
    for (int i=1; i<n; i++)
    {
        if (arr[i] != arr[i-1]+1)
        {
            ans = max(ans, i-start);
            start = i;
        }
    }
    ans = max(ans, n-start); // when subsequence is till the end
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
