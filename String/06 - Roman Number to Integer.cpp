// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int roman_to_int(char C)
{
    switch(C)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        int len=s.length();
        int ans=0;
        for(int i=0; i<len; i++)
        {
            if(i < len-1 && roman_to_int(s[i]) < roman_to_int(s[i+1]))
                ans -= roman_to_int(s[i]);
            else
                ans += roman_to_int(s[i]);
        }

        cout<<ans<<endl;
    }
    return 0;
}