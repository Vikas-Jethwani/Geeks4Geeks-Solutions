#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n;

        int arr[n], hash[100005]={0};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            hash[arr[i]]++;
        }
        cin>>k;

        int small=0, ans=-1;
        for(int i=0; i<100005; i++)
        {
            if(hash[i] > 0)
            {
                hash[i]--;
                small++;
                if(small == k)
                {
                    ans = i;
                    break;
                }
                if(hash[i] > 0) // To account for repeated elements
                    i--;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}