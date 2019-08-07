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

        stack <char> ss;
        while(!ss.empty())
            ss.pop();
        int len=s.length();
        bool ok=true;

        for(int i=0; i<len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                ss.push(s[i]);
            else
            {
                if(ss.empty())
                {
                    ok = false;
                    break;
                }
                if(s[i] == ')' && ss.top() == '(')
                    ss.pop();
                else if(s[i] == ']' && ss.top() == '[')
                    ss.pop();
                else if(s[i] == '}' && ss.top() == '{')
                    ss.pop();
                else
                {
                    ok = false;
                    break;
                }
            }
        }

        if(ok && ss.empty())
            cout<<"balanced\n";
        else
            cout<<"not balanced\n";
    }
    return 0;
}