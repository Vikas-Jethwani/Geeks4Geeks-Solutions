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

        bool found = false;
        unordered_map<char, bool> exists;
        for (int i=0; i<s.length(); i++)
        {
            if (exists[s[i]])
            {
                cout<<s[i]<<endl;
                found = true;
                break;
            }
            else
                exists[s[i]] = true;
        }

        if (!found)
            cout<<-1<<endl;
    }
    return 0;
}
