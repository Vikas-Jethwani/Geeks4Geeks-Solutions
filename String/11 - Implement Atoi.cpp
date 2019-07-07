// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int atoi(string s)
{
    int result=0, sign=1;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        if(i == 0 && s[i] == '-')
        {
            sign = -1;
            continue;
        }
        if('0' <= s[i] && s[i] <= '9')
        {
            int dig = s[i] - '0';
            result = result*10 + dig;
        }
        else
            return -1;
    }
    return sign*result;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        cout<< atoi(s) <<endl;
    }
    return 0;
}