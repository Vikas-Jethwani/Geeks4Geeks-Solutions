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

        vector<string> words;
        int len=s.length();
        string temp="";
        for(int i=0; i<len; i++)
        {
            if(s[i] == '.')
            {
                words.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        words.push_back(temp);

        for(int i=words.size()-1; i>=0; i--)
        {
            if(i == 0)
                cout<<words[i]<<endl;
            else
                cout<<words[i]<<".";
        }
    }
    return 0;
}