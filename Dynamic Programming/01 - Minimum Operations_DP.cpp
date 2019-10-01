// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 10005
int dp[MAX];

void pre_compute()
{
    dp[0] = 0;
    for(int i=1; i<MAX; i++)
    {
        dp[i] = min( (dp[i-1]+1) , (dp[i/2] + 1 + (i%2)) );
        // (i%2) => to accomodate extra operation
    }
}


int main()
{
    pre_compute();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        cout<<dp[n]<<endl;
    }
    return 0;
}
