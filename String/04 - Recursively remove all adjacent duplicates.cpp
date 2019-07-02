// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

string remove_adjacent(string s)
{
    bool changes=false;

    int len=s.length();
    char prev='-';
    for(int i=0; i<len; i++)
    {
        if(s[i] == prev)
        {
            if(i == 0)
            {
                s[i] = '-';
            }
            else
            {
                s[i-1] = s[i] = '-';
            }
            changes = true;
        }
        else
            prev = s[i];
    }

    int j=0;
    for(int i=0; i<len; i++)
    {
        if(s[i] != '-')
            s[j++] = s[i];
    }
    s.resize(j);

    if(changes == false)
        return s;
    else
        return remove_adjacent(s);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        cout<< remove_adjacent(s) <<endl;
    }
    return 0;
}