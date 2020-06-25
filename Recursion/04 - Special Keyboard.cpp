// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int ans[76];

// f(n) = max( n, 1 + f(n-1), f(n - i) * (i - 1) )
// i >= 3; if i == 2: f(n-i)*(i-1)=>f(n-i); No use
void pre()
{
    for (int i=0; i<76; i++)
        ans[i] = i;

    for (int i=3; i<76; i++)
    {
        ans[i] = max(ans[i], 1+ans[i-1]);
        for (int j=3; i-j>=0; j++) // 3 = Ctrl-A + Ctrl-C + Ctrl-V
        {
            ans[i] = max(ans[i], ans[i-j]*(j-1));
        }
    }
}


int main()
{
    pre();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        
        if (n > 75)
            cout<<-1<<endl;
        else
            cout<<ans[n]<<endl;
    }
}
