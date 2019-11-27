// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 1005
int dp[MAX][MAX];
int N;

int maxPath()
{
    for(int i=N-2; i>=0; i--)
    {
        for(int j=0; j<N; j++)
        {
            int mx = -1;
            if(j == 0)
                mx = max(dp[i+1][j], dp[i+1][j+1]);
            else if(j == N-1)
                mx = max(dp[i+1][j-1], dp[i+1][j]);
            else
                mx = max(dp[i+1][j-1], max(dp[i+1][j], dp[i+1][j+1]));

            dp[i][j] += mx;
        }
    }

    int ans = -1;
    for(int j=0; j<N; j++)
        ans = max(ans, dp[0][j]);

    return ans;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>> N;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin>>dp[i][j];

        cout<< maxPath() <<endl;
    }

    return 0;
}
