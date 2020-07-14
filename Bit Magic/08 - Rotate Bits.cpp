/*
    If we had to rotate in 32 bits, then easy:
    (n << d)|(n >> (32 - d));
    (n >> d)|(n << (32 - d));
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
        int n, d;
        cin>>n>>d;
        d %= 16;
        bitset<16> bn(n), bn1, bn2;

        for (int i=0; i<16; i++)
        {
            if (i < d)
            {
                bn1[d-i-1] = bn[16-i-1];
                bn2[16-d+i] = bn[i];
            }
            else
            {
                bn1[16-i-1+d] = bn[16-i-1];
                bn2[i-d] = bn[i];
            }
        }
        cout<<bn1.to_ulong()<<endl;
        cout<<bn2.to_ulong()<<endl;
    }
    return 0;
}
/*
// Python
for _ in range(int(input())):
    n, d = map(int, input().split())
    d = d%16
    arr = bin(n)[2:]
    while len(arr) < 16:
        arr = '0' + arr
    n1 = arr[d:] + arr[:d]
    n1 = int(n1, 2)
    n2 = arr[-d:] + arr[:-d]
    n2 = int(n2, 2)
    print(n1)
    print(n2)
*/
