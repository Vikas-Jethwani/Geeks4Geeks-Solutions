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
        int n;
        cin>>n;

        string s[n];
        int min_len=INT_MAX;
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            min_len = min(min_len, (int)s[i].length());
        }

        int end_idx=-1;
        for(int i=0; i<min_len; i++)
        {
            char curr=s[0][i];
            bool all_same=true;
            for(int j=1; j<n; j++)
            {
                if(s[j][i] != curr)
                {
                    all_same = false;
                    break;
                }
            }
            if(all_same)
                end_idx = i;
            else
                break;
        }

        if(end_idx == -1)
            cout<< -1 <<endl;
        else
        {
            for(int i=0; i<=end_idx; i++)
                cout<<s[0][i];
            cout<<endl;
        }
    }
    return 0;
}