// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 5005
int dp[3][MAX];
int N, cuts[3];

int maxRods()
{
    // 0 => No rods possible
    for(int i=0; i<=N; i++)
        dp[0][i] = dp[1][i] = dp[2][i] = 0;

    for(int j=1; j<=N; j++)
    {
        for(int i=0; i<3; i++)
        {
            if(j%cuts[i] == 0)
                dp[i][j] = j/cuts[i];
            else if(cuts[i]>j)
                continue;
            else
            {
                int mx = max(dp[0][j-cuts[i]], max(dp[1][j-cuts[i]], dp[2][j-cuts[i]]));
                if( mx != 0)
                    dp[i][j] = 1 + mx;
            }
        }
    }

    return max(dp[0][N], max(dp[1][N], dp[2][N]));
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>> N;
        cin>> cuts[0] >> cuts[1] >> cuts[2];

        cout<< maxRods() <<endl;
    }

    return 0;
}
