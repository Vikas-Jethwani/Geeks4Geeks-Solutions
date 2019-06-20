/*
    O(n^2)
    When I used Map instead of hash-array, TLE.
*/
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
        int hash[1000005] = {0};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            hash[arr[i]]++;
        }

        int ans=0;
        sort(arr, arr+n);

        for(int i=0; i<n; i++)
        {
            hash[arr[i]]--; // Use element1 => reduce freq
            for(int j=i+1; j<n; j++)
            {
                hash[arr[j]]--; // Use element2 => reduce freq
                int sum = arr[i] + arr[j];
                if(hash[sum] > 0)
                {
                    ans++;
                }
                hash[arr[j]]++; // Return element2 => increase freq
            }
            hash[arr[i]]++; // Return element1 => increase freq
        }

        if(ans == 0)
            ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}