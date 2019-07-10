// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int LCS(string s1, string s2, int len)
{
    int lcs[len+1][len+1];
    // Set first row and column = 0
    for(int i=0; i<=len; i++)
        lcs[i][0] = lcs[0][i] = 0;

    for(int i=1; i<=len; i++)
    {
        for(int j=1; j<=len; j++)
        {
            if(s1[i-1] == s2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }

    return lcs[len][len];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        int len=s.length();
        string rev=s;
        reverse(rev.begin(), rev.end());

        cout<< len - LCS(s, rev, len) <<endl;
    }
    return 0;
}