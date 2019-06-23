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

        int dpL[n]; // Left mein max kitna hai
        int dpR[n]; // Right mein max kitna hai
        dpL[0]=0;
        dpR[n-1]=0;
        for(int i=1; i<n; i++)
        {
            dpL[i] = max(dpL[i-1], arr[i-1]);
        }
        for(int i=n-2; i>=0; i--)
        {
            dpR[i] = max(dpR[i+1], arr[i+1]);
        }
        int total=0;
        for(int i=0; i<n; i++)
        {
            int possible = min(dpL[i], dpR[i]);
            if(arr[i] < possible)
                total += (possible-arr[i]);
        }

        cout<<total<<endl;
    }
    return 0;
}