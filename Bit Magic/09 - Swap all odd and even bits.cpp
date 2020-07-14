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
        bitset<32> b(n);

        for (int i=0; i<32; i+=2)
        {
            int temp = b[i];
            b[i] = b[i+1];
            b[i+1] = temp;
        }

        cout<<b.to_ulong()<<endl;
    }
    return 0;
}
