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
        long long arr[n], brr[n];

        for (int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        for (int i=0; i<n; i++)
            cin>>brr[i];
        sort(brr, brr+n);
        reverse(brr, brr+n);

        long long ans = 0;
        for (int i=0; i<n; i++)
            ans += arr[i]*brr[i];

        cout<<ans<<endl;
    }
    return 0 ;
}
