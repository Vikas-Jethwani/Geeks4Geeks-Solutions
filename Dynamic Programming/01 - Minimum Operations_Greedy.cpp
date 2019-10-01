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
        while(n > 0)
        {
            ans++;
            if(n%2 == 0)
                n /= 2;
            else
                n--;
        }

        cout<<ans<<endl;
    }
    return 0;
}