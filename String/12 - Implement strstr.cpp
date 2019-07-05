// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int strstr(string s, string x)
{
    int lens=s.length();
    int lenx=x.length();
    for(int i=0; i<lens; i++)
    {
        if(s[i] == x[0])
        {
            int j=i+1, k=1;
            while(j < lens && k < lenx)
            {
                if(s[j] == x[k])
                {
                    j++;
                    k++;
                }
                else
                    break;
            }
            if(k == lenx)
                return i;
        }
    }
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string a, b;
        cin>>a>>b;

        cout<< strstr(a, b) <<endl;
    }
    return 0;
}