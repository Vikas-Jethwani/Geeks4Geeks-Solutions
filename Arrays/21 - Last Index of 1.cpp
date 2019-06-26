#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        int pos=-1;
        int len=s.length();
        for(int i=0; i<len; i++)
        {
            if(s[i]=='1')
                pos = i;
        }

        cout<<pos<<endl;
    }
    return 0;
}