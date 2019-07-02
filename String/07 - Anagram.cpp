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
        string a, b;
        cin>>a>>b;

        int lena=a.length();
        int lenb=b.length();
        if(lena != lenb)
        {
            cout<<"NO"<<endl;
            continue;
        }

        bool same=true;
        int hash[26]={0};
        for(int i=0; i<lena; i++)
        {
            hash[a[i] - 'a']++;
            hash[b[i] - 'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(hash[i] != 0)
            {
                same = false;
                break;
            }
        }

        if(same)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}