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
        int hash[26]={0};
        int max_len=1;
        int i=0, j=0;
        while(i < len && j < len)
        {
            hash[s[j] - 'a']++;
            while(hash[s[j] - 'a'] > 1 && i <= j)
            {
                hash[s[i] - 'a']--;
                i++;
            }
            max_len = max(max_len, j-i+1);
            j++;
        }

        cout<<max_len<<endl;
    }
    return 0;
}