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

        bool sparse = true;
        for (int i=1; i<32; i++)
        {
            if ( (n&(1<<i)) && (n&(1<<(i-1))) )
            {
                sparse = false;
                break;
            }
        }

        cout<<sparse<<endl;
    }
    return 0;
}
