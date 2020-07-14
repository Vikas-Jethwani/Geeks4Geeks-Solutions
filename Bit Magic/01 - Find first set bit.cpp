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
        // Method 1:
        // if (n==0)
        //     cout<<0<<endl;
        // else
        //     cout<<__builtin_ctz(n)+1<<endl; // CTZ = count trailing zeroes


        // Method 2
        // bool done = false;
        // int ans=1;
        // while (n>0)
        // {
        //     if (n%2 == 1)
        //     {
        //         done = true;
        //         cout<<ans<<endl;
        //         break;
        //     }
        //     n /= 2;
        //     ans++;
        // }


        // Method 3
        bool done = false;
        for (int i=0; i<32; i++)
        {
            if (n & (1<<i))
            {
                done = true;
                cout<<i+1<<endl;
                break;
            }
        }
        if (!done)
            cout<<0<<endl;
    }
    return 0;
}
