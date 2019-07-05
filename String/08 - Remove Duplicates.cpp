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
        while(s.length() == 0)
            getline(cin, s);

        map<char, bool> hash;
        int len=s.length();
        for(int i=0; i<len; i++)
        {
            if(hash[s[i]] == false)
            {
                cout<<s[i];
                hash[s[i]] = true;
            }
        }

        cout<<endl;
    }
    return 0;
}