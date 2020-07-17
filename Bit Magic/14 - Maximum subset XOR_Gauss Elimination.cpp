/*
    Gauss Elimination(echelon form): O(32*n)
    Works for negative numbers too.
    Can also solve in other way: https://www.codechef.com/viewsolution/12276027
    ^ When we know max value of A[i], so we know the max value xor can take is using A[i] ki msb.
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int maxSubarrayXOR(int A[], int n)
{
    vector<bitset<64>> b;
    for (int i=0; i<n; i++)
        b.push_back( bitset<64> (A[i]) );

    bool used[n] = {false};
    for (int i=63; i>=0; i--)
    {
        long long mx=LLONG_MIN; int idx=-1;
        for (int j=0; j<n; j++)
        {
            if (used[j] == false && mx < A[j] && b[j][i]==1)
            {
                mx = A[j];
                idx=j;
            }
        }

        if (mx == LLONG_MIN)
            continue;
        used[idx] = true;
        for (int j=0; j<n; j++)
        {
            if (j != idx && b[j][i]==1) // trick is we are even xoring the used up elements
            {
                A[j] = A[j]^mx;
                b[j] = bitset<64> (A[j]);
            }
        }
    }

    long long ans=0; // Set it to something else if we have to definitely include those elements
    for (int i=0; i<n; i++) // final xor with all
        ans = max(ans, ans^A[i]);
    return ans;
}