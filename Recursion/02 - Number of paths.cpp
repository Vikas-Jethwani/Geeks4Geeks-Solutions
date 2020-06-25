// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

long long fact[20];

void factorial()
{
    fact[0] = 1;
    for (long long i=1; i<20; i++)
        fact[i] = i*fact[i-1];
}


int main()
{
    factorial();
    int T;
    cin>>T;
    while (T--)
    {
        int n, m;
        cin>>n>>m;
        
        cout<<fact[n+m-2]/(fact[n-1]*fact[m-1])<<endl;
    }
}
