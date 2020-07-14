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
        int n, l, r;
        cin>>n>>l>>r;

        for (int i=l-1; i<r; i++)
            n = n ^ (1<<i);

        cout<<n<<endl;
    }
    return 0;
}
