/*
1
5
4
2 6 9 11

My code's logic fails. O/p should've been 6
by converting arr to : 7 1 4 6
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
        int k, n;
        cin>>k>>n;

        int arr[n], mn=INT_MAX, mx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }

        if(mx - mn > k)
        {
            for(int i=0; i<n; i++)
            {
                if(arr[i] - mn < mx - arr[i])
                {
                    // close to minimum
                    arr[i] += k;
                }
                else
                {
                    // close to maximum
                    arr[i] -= k;
                }
            }

            mn=INT_MAX, mx=INT_MIN;
            for(int i=0; i<n; i++)
            {
                mn = min(mn, arr[i]);
                mx = max(mx, arr[i]);
            }
        }

        cout<< mx-mn <<endl;
    }

    return 0;
}
