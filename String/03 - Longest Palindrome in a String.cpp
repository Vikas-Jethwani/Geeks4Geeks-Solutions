// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

bool is_palindrome(string s, int i, int j)
{
    while(i < j)
    {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        int max_len=-1;
        int start, end;
        int len=s.length();
        for(int i=0; i<len; i++)
        {
            for(int j=len-1; j>=i; j--)
            {
                int len_substr = j-i+1;
                if(len_substr <= max_len)
                    break;
                if(is_palindrome(s, i, j))
                {
                    max_len = len_substr;
                    start = i;
                    end = j;
                    break;
                }
            }
        }

        for(int i=start; i<=end; i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}