// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 1005
int dp[MAX][MAX];

int main()
{
    string s1, s2 ;
    cin>> s1 >> s2 ;

    int n = s1.length(), m = s2.length();

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else
                dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1]) // String is zero based
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                // dp[i-1][j-1] => converting ith char to jth char
                // dp[i-1][j] => deleted ith char
                // dp[i][j-1] => added ith char
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;
}
