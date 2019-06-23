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

        // Hash the sqaures of input
        // range using => (10^3)^2 + (10^3)^2
        int arr[n], hash[2000005]={0};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            hash[arr[i]*arr[i]]++;
        }

        bool flag=false;
        sort(arr, arr+n);
        for(int i=0; i<n-2; i++)
        {
            int a2 = arr[i]*arr[i];
            for(int j=i+1; j<n-1; j++)
            {
                int b2 = arr[j]*arr[j];
                if(hash[a2+b2] > 0)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}