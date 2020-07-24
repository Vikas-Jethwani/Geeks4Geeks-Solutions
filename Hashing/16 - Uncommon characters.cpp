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
        string s1, s2;
        cin>>s1>>s2;

        bool hash1[26]={false}, hash2[26]={false};
        for (int i=0; i<s1.length(); i++)
            hash1[s1[i] - 'a'] = true;
        for (int i=0; i<s2.length(); i++)
            hash2[s2[i] - 'a'] = true;

        for (int i=0; i<26; i++)
        {
            if (hash1[i] ^ hash2[i])
                cout<<char(i+'a');
        }
        cout<<endl;
    }
    return 0;
}
