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
        int ans=0;
        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            ans = ans^temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
