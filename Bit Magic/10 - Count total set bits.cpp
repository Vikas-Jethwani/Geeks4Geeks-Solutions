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

        int ans = 0;
        for (int i=0; i<=n; i++)
            ans += __builtin_popcount(i);

        cout<<ans<<endl;
    }
    return 0;
}
