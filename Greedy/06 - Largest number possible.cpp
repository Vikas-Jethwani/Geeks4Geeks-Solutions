/*
    Printing a string as n(digits) can be as big as 50.
*/
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
        int n, s;
        cin>>n>>s;

        if(n*9 < s || s == 0)
            cout<<-1<<endl;
        else
        {
            string ans = "";
            for(int i=0; i<n; i++)
            {
                if(s >= 9)
                {
                    ans += "9";
                    s -= 9;
                }
                else
                {
                    ans += to_string(s);
                    s = 0;
                }
            }

            cout<< ans <<endl;
        }
    }

    return 0;
}
