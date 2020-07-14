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

        int mx=0, consec=0;
        for (int i=0; i<32; i++)
        {
            if (n&(1<<i))
                consec++;
            else
                consec = 0;
            
            mx = max(mx, consec);
        }

        cout<<mx<<endl;
    }
    return 0;
}
