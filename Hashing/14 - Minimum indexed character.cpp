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
        string str, pat;
        cin>>str>>pat;

        unordered_map<char, bool> exists;
        bool found = false;
        for (int i=0; i<pat.length(); i++)
            exists[pat[i]] = true;
        for (int i=0; i<str.length(); i++)
        {
            if (exists[str[i]])
            {
                found = true;
                cout<<str[i]<<endl;
                break;
            }
        }

        if (found == false)
            cout<<"$"<<endl;
    }
    return 0;
}
