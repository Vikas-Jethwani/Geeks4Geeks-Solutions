// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int dp[51] = {0};
    for(int i=0; i<51; i++)
    {
        if(i == 1)
            dp[i] = 1;
        else if(i == 2)
            dp[i] = 2;
        else if(i == 3)
            dp[i] = 4;
        else
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];    
    }

    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>> N;

        cout<< dp[N] <<endl;
    }

    return 0;
}
