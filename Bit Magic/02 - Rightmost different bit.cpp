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
        int n, m;
        cin>>n>>m;
        if (n == m)
        {
            cout<<-1<<endl;
            continue;
        }
        // int ans=1;
        // while (n>0 || m>0)
        // {
        //     if (n%2 != m%2)
        //     {
        //         cout<<ans<<endl;
        //         break;
        //     }
        //     n /= 2;
        //     m /= 2;
        //     ans++;
        // }
        int ans = n^m; // only difference bit remains
        for (int i=0; i<32; i++)
        {
            if (ans & (1<<i))
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
