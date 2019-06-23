#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n;

        long long arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cin>>m;

        sort(arr, arr+n);
        long long ans=1e18 + 5;
        for(int i=0; i<n-m+1; i++)
        {
            long long diff = arr[i+m-1] - arr[i];
            ans = min(ans, diff);
        }

        cout<<ans<<endl;
    }
    return 0;
}