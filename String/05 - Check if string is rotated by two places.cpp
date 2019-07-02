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
            cout<<0<<endl;
            continue;
        }

        bool possible=false;
        // Rotate Left
        bool found=true;
        for(int i=0; i<lena; i++)
        {
            if(a[i] != b[(i+2)%lena])
            {
                found = false;
                break;
            }
        }
        if(found)
            possible = true;
        // Rotate Right
        found=true;
        for(int i=0; i<lena; i++)
        {
            if(a[(i+2)%lena] != b[i])
            {
                found = false;
                break;
            }
        }
        if(found)
            possible = true;

        if(possible)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}