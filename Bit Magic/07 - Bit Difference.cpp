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
        // Method 1
        // cout<<__builtin_popcount(n^m)<<endl;

        // Method 2
        int ans = n^m, count=0;
        for (int i=0; i<32; i++)
        {
            if (ans & (1<<i))
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
