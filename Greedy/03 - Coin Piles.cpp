/*
    O(n^2) complexity. Checked if removing that pile completely.
    And also checking if removing one coin at a time works.
    Solve by taking example. Can be improved to O(n) prolly.
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
        int n, k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr+n);
        int ans=INT_MAX;
        int prev=0;
        for (int i=0; i<n; i++)
        {
            int temp = prev;
            prev += arr[i];
            for (int j=n-1; j>i; j--)
            {
                if (arr[j] - arr[i] > k)
                    temp += (arr[j] - arr[i] - k);
                else
                    break;
            }            
            ans = min(ans, temp);
        }

        cout<<ans<<endl;
    }
    return 0;
}
