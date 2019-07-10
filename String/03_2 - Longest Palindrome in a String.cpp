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
        string s;
        cin>>s;

        int len=s.length();
        int start=0, max_len=1;
        bool dp[len][len];

        // Initiall setup
        for(int i=0; i<len; i++)
            for(int j=0; j<len; j++)
                dp[i][j] = false;
        // 1-length
        for(int i=0; i<len; i++)
            dp[i][i] = true;
        // 2-length
        for(int i=0; i<len-1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                if(max_len < 2)
                {
                    max_len = 2;
                    start = i;
                }
            }
        }
        // Bottom-Up Table for length >= 3
        for(int i=len-1; i>=0; i--)
        {
            for(int j=i+1; j<len; j++)
            {
                if(dp[i+1][j-1] == true && s[i] == s[j])
                {
                    dp[i][j] = true;
                    if(max_len <= j-i+1)
                    {
                        max_len = j-i+1;
                        start = i;
                    }
                }
            }
        }

        /*
        // Debug
        cout<<"  ";
        for(int i=0; i<len; i++)
            cout<<s[i]<<" ";
        cout<<endl;

        for(int i=0; i<len; i++)
        {
            cout<<s[i]<<" ";
            for(int j=0; j<len; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<start<<" "<<max_len<<endl;
        */
        
        for(int i=start, j=0; j<max_len; i++, j++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}