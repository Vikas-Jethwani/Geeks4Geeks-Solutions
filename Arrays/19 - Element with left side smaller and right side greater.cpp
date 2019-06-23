#include<bits/stdc++.h>
//Stan
using namespace std;

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

        // Left => Max, Right => Min
        int dpL[n], dpR[n];
        dpL[0]=0;  dpR[n-1]=1e9;
        for(int i=1; i<n; i++)
        {
            dpL[i] = max(dpL[i-1], arr[i-1]);
        }
        for(int i=n-2; i>=0; i--)
        {
            dpR[i] = min(dpR[i+1], arr[i+1]);
        }
        int ans=-1;
        for(int i=1; i<n-1; i++)
        {
            if(arr[i] >= dpL[i] && arr[i] <= dpR[i])
            {
                ans = arr[i];
                break;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}